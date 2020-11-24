#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
int k,a ,e, c,t1,t2,t;
int myrandom(int l, int r)
{
    return (rand() % (r - l + 1)) + l;
}
typedef struct per
{
    int id;
    char *name;
    char instrument;
    int singer;                       //if perfomer is a muscian then this the joining singer id if he is a singer then it is same as id
    int performingstage;                 //stage id where he is performing to be
    int stat;                  //0 if stage is not assigned 1 is stage assigned 2 is he left the stage
    int arrivaltime;
    pthread_mutex_t lock;
}per;
typedef struct st
{
    int id;
    int perfm;                     //performer id who is performing on stage
    int stat;                     //0 if stage is not filled 1 if stage is filled with singer 2 if stage can not be filled with singer 
    int type;                     //0 for acoustic 1 for electric
    pthread_mutex_t lock;
}st;
typedef struct coo
{
    int id;
    char *name;
}coo;
per *perfm;
st *stage;
sem_t ac,ec,js,co;
void *coordinator(void *args)
{
    int id = ((coo *)args)->id;
    sem_wait(&co);                                  //holding the coordinator to give t shirt
    //printf("\033[1;35m");
    printf("\033[1;35m%s collecting T-shirt\n\033[0m", ((coo *)args)->name);
  //  printf("\033[0m");
    sem_post(&co);                                    //after collecting tshirt coordinater will be released
    return NULL;
}
void *singerjoin(void *args)                               //this is the fn that takes care of joining singer
{
    int id = ((per *)args)->id;
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += t;
    int s = sem_timedwait(&js, &ts);                 //timed wait for given tsec 
    pthread_mutex_lock(&perfm[id].lock);                  
    if (s == -1)
    {
        if (perfm[id].stat == 0 && perfm[id].stat != 2)        //if failed then we have to check that performer status is left or not and stage not assigned
        {
            perfm[id].stat = 2;                                 //then we have to mark this performer as left.
           // printf("\033[0;35m");
            printf("\033[0;35m%s %c left because of impatience\n\033[0m", perfm[id].name, perfm[id].instrument);
           // printf("\033[0m");
        }
        pthread_mutex_unlock(&perfm[id].lock);      //unlocking before returning
        return NULL;
    }
    if (perfm[id].stat == 1 || perfm[id].stat == 2)               //I was checking that the performer left or stage assigned then 
    {
        sem_post(&js);                                          //releasing the semaphore before return.
        pthread_mutex_unlock(&perfm[id].lock);                 //unlocking the lock
        return NULL;
    }
    for (int i = 0; i < a+e; i++)                             //if all the conditions above are satisfied then it comes to for loop.
    {
        pthread_mutex_lock(&stage[i].lock);
        if (stage[i].stat == 1)                                //checking the stage can join the performer
        {

            perfm[id].performingstage = i;                          //these are storing the singers stage and assigning staging for singer.
            perfm[id].stat = 1;
            stage[i].stat = 2;                                       //sets the stage status to not joinging by singer
            perfm[stage[i].perfm].singer=perfm[id].id;                //setting the musican singer's id to singer's id
         //   printf("\033[1;32m");
            printf("\033[1;32m%s joined %s's performance ,performance extended by 2 seconds\n\033[0m", perfm[id].name, perfm[stage[i].perfm].name);
          //  printf("\033[0m");
            pthread_mutex_unlock(&stage[i].lock);
            break;
        }
        pthread_mutex_unlock(&stage[i].lock);
    }
    pthread_mutex_unlock(&perfm[id].lock);
    return NULL;
}
void *givingec(void *args)
{
    int id = ((per *)args)->id;
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);             
    ts.tv_sec += t;
    int s = sem_timedwait(&ec, &ts);                   //timed wait for t sec
    pthread_mutex_lock(&perfm[id].lock);
    if (s == -1)
    {
        if (perfm[id].stat == 0 && perfm[id].stat != 2) //if failed then we have to check that performer status is left or not and stage not assigned
        {
            perfm[id].stat = 2;          //then we have to mark this performer as left.
        //    printf("\033[0;35m");
            printf("\033[0;35m%s %c left because of impatience\n\033[0m", perfm[id].name, perfm[id].instrument);
           // printf("\033[0m");
        }
        pthread_mutex_unlock(&perfm[id].lock);             //unlocking before return.
        return NULL;
    }
    if (perfm[id].stat == 1 || perfm[id].stat == 2)         //I was checking that whether the performer is assigned to stage or left?
    {
        sem_post(&ec);                    //releasing semaphore.
        pthread_mutex_unlock(&perfm[id].lock);          //unlocking before retrun.
        return NULL;
    }
    for (int i = a; i < a+e; i++)                     //if all conditions are satisfied that means no stage is assigned to it then loop through electric stages.
    {
        pthread_mutex_lock(&stage[i].lock);
        if (stage[i].stat == 0)                  //checking the stage is assigned to a performer or not
        {

            perfm[id].performingstage = i;               //if not assigned the setting performers stage to this stage it
            perfm[id].stat = 1;                        //and updating status as as stage assigned for performer.
            stage[i].perfm = id;                        //setting the performerid of the stage to performer id
            if (perfm[id].singer == id)
            {
                stage[i].stat = 2;                     //if he is singer then we have to update the staus of stage as singer cannot join to this stage
            }
            else
            {
                stage[i].stat = 1;                  //if he is performer the singer can join and updating the status to can join singer at this stage
                sem_post(&js);                       //increasing the semaphore js that means singer can join 
            }
            pthread_mutex_unlock(&stage[i].lock);
            break;
        }
        pthread_mutex_unlock(&stage[i].lock);
    }
    pthread_mutex_unlock(&perfm[id].lock);
    int rantime = myrandom(t1, t2);             //setting the time of duration of performance
  //  printf("\033[0;34m");
    printf("\033[0;34m%s performing %c at electric stage for %d sec\n\033[0m", perfm[id].name, perfm[id].instrument, rantime);
   // printf("\033[0m");
    sleep(rantime);                   //sleeping means that this performance is going on
    if(perfm[id].singer!=id && perfm[id].singer!=-1)          //checking singer is joined performer
    {
        sleep(2);                                            //if joined waiting two seconds
    }
    else if(perfm[id].singer!=id)                                                       
    {
        int stry = sem_trywait(&js);                //checking trywait that if the js=0 i.e singer is about to joing and not came to stage
        if (stry == -1)
        {
            sleep(2);                               //sleeping two seconds is waiting to join the singer to musician
        }
    }
    // if(perfm[id].singer!=-1 && perfm[id].singer!=id)
    // {
    //     sleep(2);
    // }

    pthread_mutex_lock(&stage[perfm[id].performingstage].lock);
    stage[perfm[id].performingstage].stat = 0;                  //reseting the stage here
    stage[perfm[id].performingstage].perfm = -1;
    pthread_mutex_unlock(&stage[perfm[id].performingstage].lock);
    pthread_mutex_lock(&perfm[id].lock);
    perfm[id].stat = 2;                                        //updating status to that he has left the stage
   // printf("\033[0;34m");
    printf("\033[0;34m%s performance at electric stage is ended\n\033[0m", perfm[id].name);
   // printf("\033[0m");
    if (perfm[id].singer != -1 && perfm[id].singer != id)
    {
        pthread_mutex_lock(&perfm[perfm[id].singer].lock);
        perfm[perfm[id].singer].stat = 2;                     //if singer is there then updating the status of the singer as left the stage.
        pthread_mutex_unlock(&perfm[perfm[id].singer].lock);
        printf("\033[0;34m%s performance at electric stage is ended\n\033[0m", perfm[perfm[id].singer].name);
    }
    pthread_mutex_unlock(&perfm[id].lock);
    if(c!=0)                                                          //checking coordinators are zero or not
    {
    pthread_t music_thread, singer_thread;
    coo music, singer;
    music.id = perfm[id].id;
    music.name = malloc(sizeof(perfm[id].name) * 2);
    strcpy(music.name, perfm[id].name);
    pthread_create(&music_thread, NULL, coordinator, &music);                     //creating threads of performer to collect tshirt parallely
    if (perfm[id].singer != -1 && perfm[id].singer != id)
    {
        singer.id = perfm[id].singer;
        singer.name = malloc(sizeof(perfm[perfm[id].singer].name) * 2);
        strcpy(singer.name, perfm[perfm[id].singer].name);
        pthread_create(&singer_thread, NULL, coordinator, &singer);             //if joined singer is there then also thread will be created to collect tshirt parallely
    }
    pthread_join(music_thread, NULL);
    if (perfm[id].singer != -1 && perfm[id].singer != id)
    {
        pthread_join(singer_thread, NULL);
    }
    }
    sem_post(&ec);           //releasing semaphore.
    return NULL;
}
void *givingac(void *args)
{
    int id = ((per *)args)->id;
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec+=t;
    int s = sem_timedwait(&ac, &ts); //timed wait for t sec
    pthread_mutex_lock(&perfm[id].lock);
    if(s==-1)
    {
        if (perfm[id].stat == 0 && perfm[id].stat != 2) //if failed then we have to check that performer status is left or not and stage not assigned
        {
            perfm[id].stat = 2; //then we have to mark this performer as left.
                                //  printf("\033[0;35m");
            printf("\033[0;35m%s %c left because of impatience\n\033[0m", perfm[id].name, perfm[id].instrument);
          //  printf("\033[0m");
        }
        pthread_mutex_unlock(&perfm[id].lock); //unlocking before returning
        return NULL;
    }
    if (perfm[id].stat == 1 || perfm[id].stat == 2) //I was checking that whether the performer is assigned to stage or left?
    {
        sem_post(&ac); //releasing semaphore.
        pthread_mutex_unlock(&perfm[id].lock); //unlocking before retrun.
        return NULL;
    }
    for (int i = 0; i < a; i++) //if all conditions are satisfied that means no stage is assigned to it then loop through acoustic stages.
    {
        pthread_mutex_lock(&stage[i].lock);
        if (stage[i].stat == 0) //checking the stage is assigned to a performer or not
        {

            perfm[id].performingstage = i; //if not assigned the setting performers stage to this stage
            perfm[id].stat = 1;            //and updating status as as stage assigned for performer.
            stage[i].perfm = id;           //setting the performerid of the stage to performer id
            if (perfm[id].singer == id)
            {
                stage[i].stat = 2; //if he is singer then we have to update the staus of stage as singer cannot join to this stage
            }
            else
            {
                stage[i].stat = 1; //if he is performer the singer can join and updating the status to can join singer at this stage
                sem_post(&js);     //increasing the semaphore js that means singer can join
            }
            pthread_mutex_unlock(&stage[i].lock);
            break;
        }
        pthread_mutex_unlock(&stage[i].lock);

    }
    pthread_mutex_unlock(&perfm[id].lock);
    int rantime = myrandom(t1, t2); //setting the time of duration of performance
                                    //   printf("\033[0;36m");
    printf("\033[0;36m%s performing %c at acoustic stage for %d sec\n\033[0m", perfm[id].name, perfm[id].instrument, rantime);
  //  printf("\033[0m");
    sleep(rantime); //sleeping means that this performance is going on
    if (perfm[id].singer != id && perfm[id].singer != -1) //checking singer is joined performer
    {
        sleep(2); //if joined waiting two seconds
    }
    else if(perfm[id].singer!=id)
    {
        int stry = sem_trywait(&js); //checking trywait that if the js=0 i.e singer is about to joing and not came to stage
        if (stry == -1)
        {
            sleep(2); //sleeping two seconds is waiting to join the singer to musician
        }
    }
    // if(perfm[id].singer!=-1 && perfm[id].singer!=id)
    // {
    //     sleep(2);
    // }

    pthread_mutex_lock(&stage[perfm[id].performingstage].lock);
    stage[perfm[id].performingstage].stat = 0; //reseting the stage here
    stage[perfm[id].performingstage].perfm=-1;
    pthread_mutex_unlock(&stage[perfm[id].performingstage].lock);
    pthread_mutex_lock(&perfm[id].lock);
    perfm[id].stat = 2; //updating status to that he has left the stage
                        // printf("\033[0;36m");
    printf("\033[0;36m%s performance at acoustic stage is ended\n\033[0m", perfm[id].name);
   // printf("\033[0m");
    if (perfm[id].singer != -1 && perfm[id].singer != id)
    {
        pthread_mutex_lock(&perfm[perfm[id].singer].lock);
        perfm[perfm[id].singer].stat = 2; //if singer is there then updating the status of the singer as left the stage.

        pthread_mutex_unlock(&perfm[perfm[id].singer].lock);
    }
    pthread_mutex_unlock(&perfm[id].lock);
    if (c != 0) //checking coordinators are zero or not
    {
    pthread_t music_thread,singer_thread;
    coo music, singer;
    music.id=perfm[id].id;
    music.name=malloc(sizeof(perfm[id].name)*2);
    strcpy(music.name,perfm[id].name);
    pthread_create(&music_thread, NULL, coordinator, &music); //creating threads of performer to collect tshirt parallely    
    if(perfm[id].singer!=-1 && perfm[id].singer!=id)
    {
        singer.id=perfm[id].singer;
        singer.name=malloc(sizeof(perfm[perfm[id].singer].name)*2);
        strcpy(singer.name, perfm[perfm[id].singer].name);
        pthread_create(&singer_thread, NULL, coordinator, &singer); //if joined singer is there then also thread will be created to collect tshirt parallely
    }
    pthread_join(music_thread,NULL);
    if (perfm[id].singer != -1 && perfm[id].singer != id)
    {
        pthread_join(singer_thread,NULL);
    }
    }
    sem_post(&ac);     //releasing semaphore
    return NULL;
}
void *regular(void * args)
{
    int id=((per*)args)->id;
    sleep(perfm[id].arrivaltime);    //waiting for the student to arrive
   // printf("\033[0;33m");
    printf("\033[0;33m%s %c arrived\n\033[0m", perfm[id].name, perfm[id].instrument);
   // printf("\033[0m");
    pthread_t actid, ectid,jstid;//according to his instrument i created noof threads as no of stages he can participate and keeping a race between then who wons they will take that stage (electric or acoustic) and proceed.
    if(perfm[id].instrument=='v')
    {
        pthread_create(&actid,NULL,givingac,&perfm[id]);
    }
    else if (perfm[id].instrument == 'b')
    {
        pthread_create(&ectid, NULL, givingec, &perfm[id]);
    }
    else if (perfm[id].instrument == 'p' || perfm[id].instrument=='g')
    {
        pthread_create(&actid, NULL, givingac, &perfm[id]);
        pthread_create(&ectid,NULL,givingec,&perfm[id]);
    }
    else if (perfm[id].instrument == 's')   //for singer extra is joining so we have another thread for joining and the race is between he takes acoustic or electric or he joins with other who wins the race they will perform correspondingly
    {
        pthread_create(&actid, NULL, givingac, &perfm[id]);
        pthread_create(&ectid, NULL, givingec, &perfm[id]);
        pthread_create(&jstid, NULL, singerjoin, &perfm[id]);
    }



    if (perfm[id].instrument == 'v')
    {
        pthread_join(actid, NULL);
    }
    else if (perfm[id].instrument == 'b')
    {
        pthread_join(ectid, NULL);
    }
    else if (perfm[id].instrument == 'p' || perfm[id].instrument == 'g')
    {
        pthread_join(actid, NULL);
        pthread_join(ectid, NULL);
    }
    else if (perfm[id].instrument == 's')
    {
        pthread_join(actid, NULL);
        pthread_join(ectid, NULL);
        pthread_join(jstid, NULL);
    }
}
int main()
{
    scanf("%d", &k);
    scanf("%d", &a);
    scanf("%d", &e);
    scanf("%d", &c);
    scanf("%d", &t1);
    scanf("%d", &t2);
    scanf("%d", &t);

    if(k<0 || a<0 || e<0 || c<0 || t1<0 || t2<0 || t1>t2)
    {
        printf("Invalidarguments");
        return 0;
    }
    perfm=malloc(k*sizeof(per));
    stage=malloc((a+e)*sizeof(st));
    char nameofp[100];
    char ins;
    int artime;
    for(int i=0;i<k;i++)
    {
        scanf("%s %c %d",nameofp,&ins,&artime);
        perfm[i].id=i;
        perfm[i].name=malloc(sizeof(nameofp)*2);
        strcpy(perfm[i].name,nameofp);
        perfm[i].instrument=ins;
        perfm[i].arrivaltime=artime;
        perfm[i].singer=-1;
        if(ins=='s')
        {
            perfm[i].singer=i;
        }
        perfm[i].performingstage=-1;
        perfm[i].stat=0;
        pthread_mutex_init(&perfm[i].lock,NULL);
    }
    for(int i=0;i<a;i++)
    {
        stage[i].id=i;
        stage[i].perfm=-1;
        stage[i].stat=0;
        stage[i].type=0;
        pthread_mutex_init(&stage[i].lock,NULL);
    }
    for(int i=a;i<a+e;i++)
    {
        stage[i].id = i;
        stage[i].perfm = -1;
        stage[i].stat = 0;
        stage[i].type = 1;
        pthread_mutex_init(&stage[i].lock, NULL);
    }
    sem_init(&ac,0,a);
    sem_init(&ec,0,e);
    sem_init(&js,0,0);
    sem_init(&co,0,c);
    pthread_t perfm_threads[k];
    for(int i=0;i<k;i++)
    {
        pthread_create(&perfm_threads[i],NULL,regular,&perfm[i]);
    }
    for (int i = 0; i < k; i++)
    {
        pthread_join(perfm_threads[i], NULL);
    }
    for (int i = 0; i < k; i++)
    {
        pthread_mutex_destroy(&perfm[i].lock);
    }
    for (int i = 0; i < a+e; i++)
    {
        pthread_mutex_destroy(&stage[i].lock);
    }
   // printf("\033[0;31m");
    printf("\033[0;31mFINISHED\n\033[0m");
   // printf("\033[0m");
}