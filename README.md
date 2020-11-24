# Question1 Report 
Normal merge sort runs faster than concurrent merge sort using process and concurrent merge sort using threads. 

## Reason: 

1. There are performance overheads while creating threads and processes. Because creating them is takes more time so it will be delayed in time. 

2. There are less context switches in normal merge sort as compared to concurrent merge sort process because this creates new processes which will lead to more context switches the info have to store in pcb and in in concurrent merge sort using thread also have context switches, but they don’t have extra pcbs. 

3. If the size of the array is very big then thread process will become faster because threads run in parallel on multiple cores which improves performance.  

4. If the array size is big then in process thing also become faster as more processes created and more CPU slices are allocated. 

5. The ratios depend upon the size of input and relative overheads. For smaller size the overheads will dominate so the lesser the performance of concurrency using process and threads than normal, for bigger size performance of concurrency using process and threads better than normal. 

## Performance Output:

In my system the output as follows:
```
11
11 10 9 8 7 6 5 4 3 2 1
Running concurrent_mergesort for n = 11
1 2 3 4 5 6 7 8 9 10 11 
time = 0.001304
Running threaded_concurrent_mergesort for n = 11
1 2 3 4 5 6 7 8 9 10 11 
time = 0.000501
Running normal_mergesort for n = 11
1 2 3 4 5 6 7 8 9 10 11 
time = 0.000017
normal_mergesort ran:
	[ 76.134624 ] times faster than concurrent_mergesort
	[ 29.239236 ] times faster than threaded_concurrent_mergesort


25
24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
Running concurrent_mergesort for n = 25
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 
time = 0.001841
Running threaded_concurrent_mergesort for n = 25
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 
time = 0.002155
Running normal_mergesort for n = 25
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 
time = 0.000018
normal_mergesort ran:
	[ 103.126699 ] times faster than concurrent_mergesort
	[ 120.751198 ] times faster than threaded_concurrent_mergesort

200
199 198 197 196 195 194 193 192 191 190 189 188 187 186 185 184 183 182 181 180 179 178 177 176 175 174 173 172 171 170 169 168 167 166 165 164 163 162 161 160 159 158 157 156 155 154 153 152 151 150 149 148 147 146 145 144 143 142 141 140 139 138 137 136 135 134 133 132 131 130 129 128 127 126 125 124 123 122 121 120 119 118 117 116 115 114 113 112 111 110 109 108 107 106 105 104 103 102 101 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
Running concurrent_mergesort for n = 200
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137 138 139 140 141 142 143 144 145 146 147 148 149 150 151 152 153 154 155 156 157 158 159 160 161 162 163 164 165 166 167 168 169 170 171 172 173 174 175 176 177 178 179 180 181 182 183 184 185 186 187 188 189 190 191 192 193 194 195 196 197 198 199 
time = 0.003092
Running threaded_concurrent_mergesort for n = 200
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137 138 139 140 141 142 143 144 145 146 147 148 149 150 151 152 153 154 155 156 157 158 159 160 161 162 163 164 165 166 167 168 169 170 171 172 173 174 175 176 177 178 179 180 181 182 183 184 185 186 187 188 189 190 191 192 193 194 195 196 197 198 199 
time = 0.003572
Running normal_mergesort for n = 200
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137 138 139 140 141 142 143 144 145 146 147 148 149 150 151 152 153 154 155 156 157 158 159 160 161 162 163 164 165 166 167 168 169 170 171 172 173 174 175 176 177 178 179 180 181 182 183 184 185 186 187 188 189 190 191 192 193 194 195 196 197 198 199 
time = 0.000044
normal_mergesort ran:
	[ 70.065080 ] times faster than concurrent_mergesort
	[ 80.933198 ] times faster than threaded_concurrent_mergesort
```

## Code breakdown:

### threadedmergesort:

tms() is my threaded mergesort fn in that I am creating two threads one is for left half array and other is for right half array.and calling the tms()fn to split the array.  I am checking whether the passing array size is greater than 5 if not then doing selectionsort . if size is greater than 5 i am initailising the struct things as arrays start index and end index and the arr and passing it to thread and the thread calls tms() and splits it and dothis process again.After creation of threads it waits for them to join back.after that merge()will be called to merge the left half and right half. 

```C
void *tms(void *a)
{
    struct arg *args = (struct arg *)a;

    int l = args->l;
    int r = args->r;
    int *arr = args->arr;
    if (l >= r)
        return NULL;
    if(r-l+1<=5)
    {
        selectionSort(arr,l,r);
        pthread_exit(0);
    }

    int m = l + (r - l) / 2;
    //sort left half array
    pthread_t tid1,tid2;
    
    struct arg a1;
    a1.l = l;
    a1.r = m ;
    a1.arr = arr;
   // pthread_t tid1;
    pthread_create(&tid1, NULL, tms, &a1);
    
    
    
    //sort right half array
    
    struct arg a2;
    a2.l = m+ 1;
    a2.r = r;
    a2.arr = arr;
  //  pthread_t tid2;
    pthread_create(&tid2, NULL, tms, &a2);
    
    
    //wait for the two halves to get sorted
    
    pthread_join(tid1, NULL);
    
    pthread_join(tid2, NULL);
    
    merge(arr,l,m,r);
    pthread_exit(0);
    //merge(arr,l,r);
}
```
### concurrent procces mergesort:

mpms() is my fn which does merge sort by creating process, In this the main process creates two childs one will take care of left half array and other will take care of right half. In child process it calls mpms() with the start and end index of array and after executing that doing exit(1) exiting child process. I am checking the array size is greater than 5 if less than 5 do selectionsort , after left and right child exits the two arrays are merged by merge().

```C
void mpms(int *a,int l , int r)
{
    if (l < r)
    {
        if (r - l + 1 <= 5)
        {
            selectionSort(a, l, r);  
            return;
        }

        int m = l + (r - l) / 2;
        int pid1 = fork();
        int pid2;
        if (pid1 == 0)
        {
            
                mpms(a, l, m);
                _exit(1);
            
            
        }
        else
        {
            pid2 = fork();
            if (pid2 == 0)
            {
                
                    mpms(a, m + 1, r);
                    _exit(1);
                
                
                
            }
            else
            {
                int status;
                waitpid(pid1, &status, 0);
                waitpid(pid2, &status, 0);
            }
        }
        merge(a, l, m, r);
        return;
        
    }
}

```
### normal mergesort:

mergesort() is my normal merge sort fn in that I am checking that array size is less than five or not if less then doing selectionsort after that arrays are merged by merge().
```C
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        if (r - l + 1 <= 5)
        {
            selectionSort(arr, l, r);
            return ;
        }
        
        
        int m = l + (r - l) / 2;
        
            mergeSort(arr, l, m);
        
        
            mergeSort(arr, m + 1, r);
        
        
        merge(arr, l, m, r);
        
    }
}
```

merging fn does merging of the left half and right half:
```C
void merge(int arr[], int l, int m, int r)
```

shareMem functions gets shared memory of the size mentioned by argument size.
```C
int *shareMem(size_t size)
{
    key_t mem_key = IPC_PRIVATE; //It is the numeric key to be assigned tothe returned shared memory segment
    int shm_id = shmget(mem_key, size, IPC_CREAT | 0666); //creating and granting read and write access

    return (int *)shmat(shm_id, NULL, 0); //shmat() returns the address of the attached shared memory, NULL, the system chooses a suitable(unused) page - aligned address to attach the segment.
    //0 is read-only
}
```

All callings all from int main()


# Question-2 Report
## Idea
In my idea all students are student threads, vaccination zones are vaccination zone threads and companies are company threads, students wait on the vaccination zones to get slots and vaccination zone waits on the companies for vaccines to produce. I have arrays and structures for each thing i.e for students i have st struct and s as array , for vaccination zone vz as struct and v as array and companies comp as struct and c as array.*I commented the code for more explaination.*

## Implementation
required structs and arrays;
comments are self explanatory for struct variables.
```C
int m, n ,o;
typedef struct comp
{
    int id;
    long double prob;            //succes probability of vaccine
    int noofbatches;              //stores nof batches 
    int noofvaccines;             //stores nof vaccines per batch
    int givestonoofvzones;         //stores for how many vaccination zones it can give
    pthread_mutex_t lock;
}comp;
typedef struct vz
{
    int id;
    int vc;
    long double prob;            //succes probability of vaccine
    int noofvaccines;             //noof vaccines in vaccination zone
    int slots;                    //noof slots declared
    int noofslotsgiven;                //noof slots booked
    int comanyid;                   //storing company id which has given a batch
    pthread_mutex_t lock;
}vz;
typedef struct st
{
    int id;
    int round;
    int result;
}st;
comp *c;
vz *v;
st *s;
long double p[10005];
int nos;
int ws;
pthread_mutex_t mutex;

```

other neccesary functions :
```C
int myrandom(int l, int r)
{
    return (rand() % (r - l + 1)) + l;
}
int antib(long double prob)
{
    long double rr = (long double)rand() / RAND_MAX;
    if (rr > prob)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int minimum(int a,int b,int c)
{
    if(a<=b && a<=c)
    {
        return a;
    }
    else if (b<=c && b<=a)
    {
        return b;
    }
    else
    {
        return c;
    }

}

```

In int main I am initialising the struct variables and creating threads for each student , each vaccination zone and each company,

```C
c=malloc(n*sizeof(comp));
v=malloc(m*sizeof(vz));
s=malloc(o*sizeof(st));
nos=o;
ws=0;
printf("Give me the probabilities\n");
for(int i=0;i<n;i++)          //initialising companies
{
    c[i].id=i;
    c[i].noofbatches=0;
    c[i].noofvaccines=0;
    c[i].givestonoofvzones=0;
    scanf("%Lf",&c[i].prob);
    pthread_mutex_init(&c[i].lock,NULL);
}
pthread_mutex_init(&mutex,NULL);
for(int i=0;i<m;i++)           //initialising vaccine zones
{
    v[i].id=i;
    v[i].vc=0;
    v[i].noofslotsgiven=0;
    v[i].noofvaccines=0;
    v[i].prob=0;
    v[i].slots=0;
    v[i].comanyid=-1;
    pthread_mutex_init(&v[i].lock,NULL);
}
for(int i=0;i<o;i++)               //initialising students
{
    s[i].id=i;
    s[i].round=1;
    s[i].result=0;
}
printf("BeginSimulation\n");
pthread_t company_thread[n],vaccination_thread[m],student_thread[o];
for(int i=0;i<n;i++)
{
    pthread_create(&company_thread[i],NULL,fncompany,&c[i]);     //creating thread for companies
}
for(int i=0;i<m;i++)
{
    pthread_create(&vaccination_thread[i],NULL,fnvzone,&v[i]);   //creating thread for vaccinezones
}
for(int i=0;i<o;i++)
{
    pthread_create(&student_thread[i],NULL,fnstudent,&s[i]);          //creating thread for students
}
```

### fncompany():
This function will be called by the company thread.the company have to prepare vaccines so the batches will be created randomly from 1 to 5 and noof vaccinesperbatch is created randomly betwee 10 to 20 after that the sleep is to time taken to prepare and after that we have to lock and assign the values of batches , vaccines and noofvzones it gives to in c array and unlock the lock, we will wait for the all batches taken by vzones to vaccinate and complete the vaccines then only the company will produce another time thats why i kept it in the while loop. In between if no of students become zero then company have to exit.

```C
void *fncompany(void *args)
{
    int id=((comp*)args)->id;
    int noofbatches;
    int noofvaccinesperbatch;
    while(nos>0)                 //should goto infinite loop upto nos>0 as a company is keep giving vaccines
    {
        noofbatches=myrandom(1,5);      //taking noof batches between 1 to 5 randomly
        noofvaccinesperbatch=myrandom(10,20);       //taking the vaccines perbatch randomly form 10 to 20
        printf("Pharmaceutical Company with id %d is preparing %d batches of vaccines which have success probability %Lf\n",c[id].id,noofbatches,c[id].prob);
        sleep(myrandom(2,5));       //takes time to prepare
        printf("Pharmaceutical Company with id %d has prepared %d batches of vaccines which have success probability %Lf\n", c[id].id, noofbatches, c[id].prob);
        pthread_mutex_lock(&c[id].lock);
        c[id].noofbatches=noofbatches;               //setting the prepares noof batches and noof vaccines per batch
        c[id].noofvaccines=noofvaccinesperbatch;
        c[id].givestonoofvzones=noofbatches;       //As the noof batches is numner of vaccination zones taht company may give.
        pthread_mutex_unlock(&c[id].lock);

        while(c[id].givestonoofvzones!=0)           //waiting to be complete all the batches given to the  vaccinationzones  by vaccination
        {
            if(nos==0)                            // in between nos becomes zero then we have to return
            {
                return NULL;
            }
        }
        printf("All the vaccines prepared by Pharmaceutical Company with id %d are emptied. Resuming production now.\n",c[id].id);
    }
    return NULL;
}
```

### fnvzone():
This function is called by the vaccinationzone thread it runs till all the students are proccessed. The vaccination zone first have to take vaccines form company.
the comments in the code explains the filling of vaccines by a company.
```C
int id=((vz*)args)->id;
    int noofslots;
    while(nos>0)          //we have to execute upto nos>0
    {
         int i=0;
         while(nos>0)        //the vaccinations zones have to have vaccines when nos>0
         {
             pthread_mutex_lock(&c[i].lock);  //lock to ensure that no two vaccinezone effect the comapany
             if(c[i].noofbatches>0)             //if they have batches then give one batch to vaccination zone
             {
                 c[i].noofbatches--;                //decrementing as one batch is given to vaccinataion zone
                 pthread_mutex_lock(&v[id].lock);
                 v[id].noofvaccines=c[i].noofvaccines;       //taking the vaccines in a batch of comapany to a vaccination zone 
                 v[id].prob=c[i].prob;                       //taking the succes probability of vaccine
                 v[id].comanyid=c[i].id;                        //storing the comapany which gave vaccines to vaccination zone

                 pthread_mutex_unlock(&v[id].lock);
                 pthread_mutex_unlock(&c[i].lock);
                 printf("Pharmaceutical Company with id %d is delivering a vaccine batch to Vaccination Zone with id %d which has success probability %Lf\n", c[i].id, v[id].id, v[id].prob);
                 sleep(1);             //time takes to deliver
                 printf("Pharmaceutical Company with id %d has delivered vaccines to Vaccination zone with id %d, resuming vaccinations now\n", c[i].id, v[id].id);
                 break;
             }
             pthread_mutex_unlock(&c[i].lock);        //if this company does not have batches i,e this if will not work so we have to un lock
             i=(i+1)%n;               //iterate through companies
         }
```

After filling the vaccines in vaccination zone now it has to declare slots for students to register the slot.
we have to declare slots until noof vaccines in the zone to be completed. at first we will wait for the students to come. after that we will take the noof slots as randomly between 1 to minimum(8,v[id].noofvaccines,cpyws) here cpys is copy of value of ws while waiting. we will use lock for updating slots variable to noof slots and vaccination phase as 0 (not vaccinating). after we will busy wait for the slot to be zero or waiting students to be zero, then we will lock the part we are updating the noof slots given i.e all slots may not be taken at that time the waiting students may be zero so we will store no of slots students has booked.and turning into vaccination phase after that we will busy wait to complete vaccinating i.e noofslotsgiven becomes zero if in between noof students becomes zero then we have to exit. after all vaccinated in this vaccination zone i will check that noof vaccines are zero other wise we have to declare the slots again.= until noof vaccines becomes zero.If noof vaccines becomes zero then we will reset the vaccination zone and decrementing the giventonoofvzones variable in company to know that the company used one batch, And again this vaccination zone will fill vaccines with comapany as noof students availabe.
```C
while(v[id].noofvaccines>0)        //this slot declaration part if noofvaccines in the vaccinaion zone are there.
{
    v[id].vc=0;                   //making sure that vaccination zone is not in vaccination phase to declare slotes
    int cpyws;
    while((cpyws=ws)<=0)            //waiting for the students to come if ws is 0 then we have to wait for more students to occur
    {
        if(nos==0)                  //while waiting if the noof studnets =0 then we have to return 
        {
            return NULL;
        }
    }
    noofslots=myrandom(1,minimum(8,v[id].noofvaccines,cpyws));  //declaring slots according to noofvaccines that vaccinationzone have and waiting students
    pthread_mutex_lock(&v[id].lock);
    v[id].slots=noofslots;
    printf("Vaccination Zone with id %d is ready to vaccinate with %d slots\n",v[id].id,noofslots);
    v[id].vc=0;                  //making sure that the vaccination zone in not in vaccination phase as studnets has to book slots
    pthread_mutex_unlock(&v[id].lock);
    while(v[id].slots>0 && ws>0)     // waiting for slots to be booked upto slots >0 and noof waiting students >0 
    {

    }
    pthread_mutex_lock(&v[id].lock);
    v[id].noofslotsgiven = noofslots-v[id].slots;       //setting no of slots given i.e noof slots booked
    v[id].vc = 1;                                  //entering into vaccintion phase
    printf("Vaccination Zone with id %d entering Vaccination Phase\n",v[id].id);
    pthread_mutex_unlock(&v[id].lock);
    while(v[id].noofslotsgiven>0)                //waiting to vaccinate the slot booked students.
    {
       if(nos==0)                            //while in between nos becomes 0 then return 
       {
           return NULL;
       }
    }
    pthread_mutex_lock(&v[id].lock);
    if(v[id].noofvaccines>0)                    //checking that the vaccines are over or not in vaccination zone
    {                                           //if not over then we have to make slots for the rest of vaccines left
        v[id].vc=0;                             //setting it to not vaccinating phase
        v[id].noofslotsgiven=0;                 //setting noof slots and booked slots to 0
        v[id].slots=0;
        pthread_mutex_unlock(&v[id].lock);
        continue;                               //and continue to again slot declaration
    }
    else
    {                                          //if they are over then we will make sure that all will zero 
        v[id].noofslotsgiven=0;
        v[id].noofvaccines=0;
        v[id].prob=0;
        v[id].slots=0;
        v[id].vc=0;
        printf("Vaccination Zone with id %d has run out of vaccines\n",v[id].id);
        pthread_mutex_unlock(&v[id].lock);
        pthread_mutex_lock(&c[v[id].comanyid].lock);
        c[v[id].comanyid].givestonoofvzones--;     //decrasing the noofgivenvzones in company 
        pthread_mutex_unlock(&c[v[id].comanyid].lock);
        pthread_mutex_lock(&v[id].lock);
        v[id].comanyid=-1;                          //setting the vaccinationzone's company to -1 i.e no company is assigned to this vzone
        pthread_mutex_unlock(&v[id].lock);
    }
}
```

### fnstudent():
This funtion will be called by student thread. The student will arrive late so we sleep for sec between 1 to 5 randomly.Then we enter the while loop if the students result is 0(tested negative in antibody test) and the student round is <=3. As we enter the loop we will increase waiting students and we will iterate through the vaccination zones which has slots and it is not in vaccination phase. after satisfying these the student will enter and decrease the slots and waiting students. and they will busy wait until the vaccination phase begins. After vaccination phase begins we have to decrement the noof vaccines and noofslotsgiven because the students are vaccinating we will do sleep 1 after this becasue he is taking time for vaccination after vacinating the students will take antibody test i.e a fn which takes the probability of vaccine to success and make random value and checking with probabilty if random value > probabilty then it is succeded(i.e psoitive) otherwise failed (i.e negative) after that we are sleeping i.e time taken to test . after that we will check the result . if result is 0 then he is negative and doing round++ i.e going vaccination for another round other wise student is vaccinated and getts out of the loop and if the student got out of the loop and his result is 0 then he has to go to home otherwise going to school any ways the students are gone form vaccinating so noof students is decremented and exiting.
```C
void *fnstudent(void *args)
{
    sleep(myrandom(1,5));          //sleeping between 1,5 is the students not coming at time
    int id=((st*)args)->id;
    while(s[id].result==0 && s[id].round<=3)   //if students round should be less than 3 and his result should be negative i.e 0 for to enter this vaccinations
    {
        printf("Student with id %d has arrived for his %d round of Vaccination\n",s[id].id,s[id].round);
        printf("Student with id %d is waiting to be allocated a slot on a Vaccination Zone\n",s[id].id);
        int i=0;
        pthread_mutex_lock(&mutex);               // locking because ws is the critical section for student
        ws++;                                 //increasing the stundents who are waiting
        pthread_mutex_unlock(&mutex);
        while(nos)                           //while no of students >0 
        {
            pthread_mutex_lock(&v[i].lock);          //lock to avoid multiple students to be accessed at same time 
            if(v[i].slots>0 && v[i].vc==0)         //if slots are there and the vaccination zone is not in vaccination phase then we have to declare slots
            {
                pthread_mutex_lock(&mutex);    //lock as this the critical section for students
                ws--;                       //as slot is given to student then the student is not waiting for the slot
                pthread_mutex_unlock(&mutex);
                v[i].slots--;                 //as slot is given to student then slots should be decreased.
                printf("Student with id %d assigned a slot on the Vaccination Zone with id %d and waiting to be vaccinated\n",s[id].id,v[i].id);
                pthread_mutex_unlock(&v[i].lock);  //unlocking the vaccination lock
                while(v[i].vc==0)                  //waiting for the zone to enter vaccination phase
                {

                }
                pthread_mutex_lock(&v[i].lock);  //lock as multiple students cannot acces the thing in same time
                v[i].noofvaccines--;             //as the students is vaccinates the the noofvacines should be decrement
                v[i].noofslotsgiven--;           //so the actual slots given to students to be drecremented (v[i].slots is not actual slots the actual slots booked is less than or equal to this so we have to decrement this)

                pthread_mutex_unlock(&v[i].lock);
                sleep(1);                  //sleep the student to be vaccinated as vaccination takes some time.
                printf("Student with id %d on Vaccination Zone with id %d has been vaccinated which has success probability %Lf\n", s[id].id, v[i].id, v[i].prob);
                pthread_mutex_lock(&mutex);
                s[id].result=antib(v[i].prob);  //checking that the students has tested positive or negative for antibodies
                sleep(1);
                if(s[id].result==0)
                {
                    printf("Student with id %d has tested negative for antibodies.\n",s[id].id);
                    s[id].round++;  //as it is negative so we have to increment his round to vaccinate again
                    pthread_mutex_unlock(&mutex);
                    break;
                }
                else
                {
                    printf("Student with id %d has tested positive for antibodies.\n",s[id].id);
                    pthread_mutex_unlock(&mutex);
                    break;
                }
            }
            pthread_mutex_unlock(&v[i].lock);   //unlocking the vaccination lock if the if statement is not worked
            i=(i+1)%m;                //iterate through vaccination zones
        }
    }
    if(s[id].result==0)        //if the result is zero after rthe while loop then he should go to homw
    {
        printf("student with id %d should go to home for another online semester\n", s[id].id);
    }
    pthread_mutex_lock(&mutex); // as nos is critical section for students
    nos--;                     // as the students completed his vaccinatio no of students should be reduced
    pthread_mutex_unlock(&mutex);
    return NULL;

}
```

we have to wait for all the threads to join and destroy the locks:
```C
for (int i = 0; i < n; i++)
    {
        pthread_join(company_thread[i], NULL);
    }
    for (int i = 0; i < m; i++)
    {
        pthread_join(vaccination_thread[i], NULL);
    }
    for (int i = 0; i < o; i++)
    {
        pthread_join(student_thread[i], NULL);
    }

    for (int i = 0; i < n; i++)
    {
        pthread_mutex_destroy(&c[i].lock);
    }
    for (int i = 0; i < m; i++)
    {
        pthread_mutex_destroy(&v[i].lock);
    }
    pthread_mutex_destroy(&mutex);

    printf("Simulation Over\n");
```# Question-3 Report

## Idea
I am taking every performer as a thread. when the performer is arrived.I divided threads as per their instruments. main classification is
### Performer is a musician:
After dividing the performers by instruments we will talk only for musician here . If the musician has chance of taking two stages then i am creating two threads and keeping a race between theese two threads which ever takes the stage first the performer will perform on that stage which is decided by thread like if the acoustic thread aquires a stage then the performer will perform on acoustic stage. so I have two fn's here givingac() and givingec() the acoustic thread will call givingac() simlarly electric thread in that fn In that fns when the thread calls the fn stat varialble in perfm struct will assign the stage. so after going to these fn first i will check the stat is assigned or not if not assigned then goto this stage if assigned then leave this fn like that So the performer goes to the stage and In that fn's we have loop looping through respective stages i.e. acoustic stages in givingac(). as he is musician we will mark the stage as a singer can join and after if the singer joins we will wait for two seconds else normal and the performer has duration to perform after this duration the musician an singer will leave the stage if singer joined musician and if singer is joined then after leaving the stage I am calling two threads one is musician and singer and passes to coordinate fn to collect tshirts parallely after that the musician and joined singer will exit. And if the muscian can perform only in one stage then no racing and this thread will normally call and do the same.

### performer is a singer:
As singer can join a musician , so I am creating three threads acoustic ,electric ,joiningmusician and keeping race between them if the electric wins that means singer performs on electric stage and nobody can join singer similarly acoustic wins, If joiningmusician wins that means singer has to join the stage with musician. so the acoustic and electric parts are same for singer and musician, as joiningmusician wins as the thread calls singerjoin() fn inthat same as givinga() to check whethere the stage is assigned or not and after that we will loop through all stages because he can join any stage, and checking the stage can hae joining option if there then joins.

## Implementation functions
### variables
In this code I have 4 semaphores name ac,ec,js,co. as ac is the semaphore which takes care of how many acoustics available similarly ec , js is the semaphore that which takes care of how many stages can the singer may join, co is the semaphore that takes care about how many coordinators for giving tshirt.
and I have  structs per which is performer things and st which is stage things and coo is the struct which is passing to coordinator fn to collect tshirts
for performer:
as comments and the names says the functionality of that variable 
```C
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
```

for stage :
as comments and the names says the functionality of that variable
```C
typedef struct st
{
    int id;
    int perfm;                     //performer id who is performing on stage
    int stat;                     //0 if stage is not filled 1 if stage is filled with singer 2 if stage can not be filled with singer 
    int type;                     //0 for acoustic 1 for electric
    pthread_mutex_t lock;
}st;

```

for passing to coordinator():
as comments and the names says the functionality of that variable
```C
{
    int id;
    char *name;
}coo;
```
I have arrays perfm and stage to with datatypes as respective structs, ressembles as each instance of array is a performer and identified by id of the performer and similarly for stage.

usefull funtions:
myrandom() gives the random number between the l and r;
```C
int myrandom(int l, int r)
{
    return (rand() % (r - l + 1)) + l;
}
```

### regular():
In regular fn i will create the threads for racing between the stages of the performer, and for singer i created three threads as it has to has three options so race between three options. This funtion takes care about creating threads according to number of stages and for singer one extra thread for joiningmusician.
after all threads executed will wait the threads to join and exits the fn.
```C
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
```

### givingac():
As we are keeping the race between threads one of the threads call this fn or the musician with only one stage will create thread  and call this fn
As the thread called this fn first we do timed wait on semaphore ac (i.e ac is no acoustic stages available). that means the performer only wait t seconds for a to be assigned to a stage, if the stage is not avaible for more than t seconds the performer will exit due to impatience. i.e. when the timewait fails we have to check that the performer status as left or not and not assigned. if the status is left then the thread will just exit if he did not left and stage is assigned then also the thread just exits. if status is not left and not assigned then we have to assigned the status as left and exits the fn. and if it succeded the againg we have to check the status. if the status is assigned i.e the other thread came first and taken the stage in that case this thread no longer should exist  and if the status is left i.e if the other thread came first and exited because of timed wait or whole performance is over so as the win of the race is decided by who came first . if the first one lefted then the other threads comperting this also should be exited and as this if condition is checked i.e it decremented the semaphore so while we leaving we have to increment the semaphore and exit.

```C
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
```

if all the above condistions satisfiesd then we have to loop through the stages as this fn is acoustic stage so we have iterate through acoustic stage only we will now lock the stage to not acces the inner data by multiple performers and check the stage is assigned or not if not assigned then we wil update the performers performingstage and performer status as stage assigned and stage stores the performer and checks if the performer is singer or not if performer is singer then the stage status updates as nosinger can join, if the performer is musician then the stage staus is updated to singer can join and increment the semaphore js(i.e available stages to join).after that unlocking the stage and breaking out of the loop.

```C
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

```

after taking the stage the performance of the performer will have a duration between t1 and t2 randomly so myrandom fn returns random no between t1 and t2, so sleeping that much time indicating the performance is going on for that time. after this we will check that if the singer is joined or not i.e performers singer variable is the id of the singer, if that id is same as this performer id then the performer is a singer if it is -1 that means no singer is joined other wise singer is joined, as singer is joined the performance has to be extended by 2 seconds. if not joined I am using sem_trywait() it returns -1 as the semaphore is 0 and returns 0 as the semaphore is >0 here the semantic is if the semtrywait() fails i.e the js is 0, that means as he is a musician he incremented the js that means js have to be atleast 1 but now if the js is 0 that means the singer takes the semaphore but he is not joined so we will wait for 2sec to be joined. As the performane is over the performers to be left as the perfomers are leaving we have to reset the stage variables and set the performers status as left, After this these performers have to be get tshirts so I created threads as many as no of performers and called the coordinator fn because the tshirts should be collected parallelly.

```C
int rantime = myrandom(t1, t2); //setting the time of duration of performance
                                    //   printf("\033[0;36m");
    printf("\033[0;36m%s performing %c at acoustic stage for %d sec\n\033[0m", perfm[id].name, perfm[id].instrument, rantime);
  //  printf("\033[0m");
sleep(rantime); //sleeping means that this performance is going on
    if (perfm[id].singer != id && perfm[id].singer != -1) //checking singer is joined performer
    {
        sleep(2); //if joined waiting two seconds
    }
    else if (perfm[id].singer!=id)
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
```
after this these thread will go to coordinator fn and waits for the co semaphore(i.e noof coordinators available) prints he is collected tshirt and sem_post the co and returns from the fn.

```C
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
```

### givingec()
This function is same as givingac() fn just is the difference is using semaphore ec instead of ac and looping through electirc stage i.e i is looping through a to   a+e. the threads have race so one of the thread goes to following fn and change their statuses before the other thread changes the change the status and only one thread continues to allocating and performing on the stage.

### singerjoin()
This fn is the called by one of the threads created by the singer which are in race. the checking of timed wait and the stage is assigned or not conditions are same only difference is it loops through all the stages and check the status of the stage if the status of the stage is singer can join the the singer updates his status to stage assigned and the stage staus will be assigned to nosingerjoin and the musician's singer id is change to this id and who is performing on the stage. and breaking out of the loop and exits. Here the semaphore used is js.


```C
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
```
So Afher the singer has joined the stage .this will be resumed in the musicians stage fn i.e givingac() or givingec() in that they will check the muscian is joined or not. And they create thread of the singer to collect tshirt there. So singer also will collect the tshirt and the performers who left cannot get the tshirt.
