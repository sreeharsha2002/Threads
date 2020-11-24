#define _POSIX_C_SOURCE 199309L //required for clock
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <limits.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>
#include <inttypes.h>
#include <math.h>
typedef struct arg
{
    int l;
    int r;
    int *arr;
}arg;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int *shareMem(size_t size)
{
    key_t mem_key = IPC_PRIVATE; //It is the numeric key to be assigned tothe returned shared memory segment
    int shm_id = shmget(mem_key, size, IPC_CREAT | 0666); //creating and granting read and write access

    return (int *)shmat(shm_id, NULL, 0); //shmat() returns the address of the attached shared memory, NULL, the system chooses a suitable(unused) page - aligned address to attach the segment.
    //0 is read-only
}
void selectionSort(int arr[],int l, int r)
{
   // printf("sele");
    int i, j, min_idx;

    for (i = l; i <=r; i++)
    {
        min_idx = i;
        for (j = i + 1; j <=r; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

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
int main()
{
    struct timespec ts;


    long long int n;
    scanf("%lld",&n);
    int *a = shareMem(sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int b[n + 1];
    int c[n + 1];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i];
    }
    printf("Running concurrent_mergesort for n = %lld\n", n);
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    long double st = ts.tv_nsec / (1e9) + ts.tv_sec;    

    //multiprocess mergesort
    mpms(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    long double en = ts.tv_nsec / (1e9) + ts.tv_sec;
    printf("time = %Lf\n", en - st);
    long double t1 = en - st;

    pthread_t tid;
    struct arg arr;
    arr.l = 0;
    arr.r = n - 1;
    arr.arr = b;
    printf("Running threaded_concurrent_mergesort for n = %lld\n", n);
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    st = ts.tv_nsec / (1e9) + ts.tv_sec;

    //multithreaded mergesort
    pthread_create(&tid, NULL, tms, &arr);
    pthread_join(tid, NULL);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr.arr[i]);
    }
    printf("\n");
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    en = ts.tv_nsec / (1e9) + ts.tv_sec;
    printf("time = %Lf\n", en - st);
    long double t2 = en - st;

    printf("Running normal_mergesort for n = %lld\n", n);
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    st = ts.tv_nsec / (1e9) + ts.tv_sec;
    mergeSort(c, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    en = ts.tv_nsec / (1e9) + ts.tv_sec;
    printf("time = %Lf\n", en - st);
    long double t3 = en - st;

    printf("normal_mergesort ran:\n\t[ %Lf ] times faster than concurrent_mergesort\n\t[ %Lf ] times faster than threaded_concurrent_mergesort\n\n\n", t1 / t3, t2 / t3);
    shmdt(a);
    return 0;
}
