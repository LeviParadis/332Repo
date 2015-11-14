#include "dogwashsynch.h"
#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
    
//initializes locks and variables returns 0 for sucess and -1 for faliure
int dogwash_init(int numbays,dogwash *d)
{
 
    printf("Initializing dog bay \n");
    d->curnumbays = 0;
    d->totaldogs = 0;
    d->dogAs = 0;
    d->dogBs = 0;
    d->dogOs = 0;
    d->totalbays = numbays;
    
    return 0;
}

//Called when new dog arrives, returns when dog is being washed 
// Takes a dogtype and a pointer to a dogwash structure as a variable
// returns 0 for success and -1 for faliure
int newdog(dogtype dogToWash, dogwash *d)
{
    sem_wait(&lock); // "locks"
    while (d->curnumbays > d->totalbays)
    {
        printf("Waiting for bays to be open..\n");
        sem_wait(&cond);
    }
    printf("A bay was open checking dog types...\n");
    switch(dogToWash)
    {
        case DA:
            while(d->dogBs > 0)
            {
                printf("There is a DB dog in the wash, waiting...\n");
                sem_wait(&cond);           
            }
            break;
        case  DB:
           while(d->dogAs > 0)
            {
               printf("There is a DA dog in the wash, waiting...\n");
               sem_wait(&cond);
           }        

           break;
    }   
    
    printf("Dog is now being washed \n ");
    switch(dogToWash)
    {
            case DA:
                d->dogAs++;
                printf("Adding a dog A to the list\n");
                break;
            case DB:
                d->dogBs++;
                printf("Adding a dog B to the list\n");
                break;
    //No DO case unless a reason to make one arises
    }
    d->curnumbays++;
    sem_post(&lock); // "unlocks"
    return 0;
}
// called when dog is done being washed, returns after dog is removed
// returns 0 for success and -1 for faliure
int dogdone(dogtype dogToWash,dogwash *d)
{
        sem_wait(&lock); // "locks"
        switch(dogToWash)
    {
            case DA:
                d->dogAs--;
                sem_post(&cond);
                break;
            case DB:
                d->dogBs--;
                sem_post(&cond);
                break;
	    case DO:
                sem_post(&cond);
    //No DO case unless a reason to make one arises
    }
    printf("Dog is now done being washed, GO HOME! \n");
    d->curnumbays--;
    sem_post(&cond);
    sem_post(&lock); // "unlocks"
    return 0;
}
//Called when data clean up is required, destroys locks
// returns 0 for success and -1 for faliure
int dogwash_done()
{
    return 0;
}
