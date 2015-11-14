#include "dogwashsynch.h"
#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

    struct dogwash *d = NULL;

    sem_t lock;
    sem_t condBays;
    sem_t condDogs;
 
//initializes locks and variables returns 0 for sucess and -1 for faliure
int dogwash_init(int numbays)
{
 
    printf("Initializing dog bay \n");
    d = malloc(sizeof(struct dogwash));
    d->curnumbays = 0;
    d->totaldogs = 0;
    d->dogAs = 0;
    d->dogBs = 0;
    d->totalbays = numbays;
    d->counterDA = 0;
    d->counterDB = 0;
    
    sem_init(&lock,0,1); // Initializing seph to 1 so it works as a lock
    sem_init(&condBays,0,0); // Initializing seph to 0 so it works as a condition variable
    sem_init(&condDogs,0,0); 
    return 0;
}

//Called when new dog arrives, returns when dog is being washed 
// Takes a dogtype and a pointer to a dogwash structure as a variable
// returns 0 for success and -1 for faliure
int newdog(dogtype dogToWash)
{
    sem_wait(&lock); // "locks"
    while (d->curnumbays > d->totalbays)
    {
        printf("Waiting for bays to be open..\n");
        sem_wait(&condBays);
    }
    printf("A bay was open checking dog types...\n");
    switch(dogToWash)
    {
        case DA:
            while(d->dogBs > 0 && d->counterDA < 10)
            {
                printf("There is a DB dog in the wash, waiting...\n");
                sem_wait(&condDogs);           
            }
            break;
        case  DB:
           while(d->dogAs > 0 && d->counterDB < 10)
            {
               printf("There is a DA dog in the wash, waiting...\n");
               sem_wait(&condDogs);
           }        

           break;
    }   
    
    printf("Dog is now being washed \n ");
    switch(dogToWash)
    {
            case DA:
                d->dogAs++;
                d->counterDA++;
                d->counterDB = 0; //Counters are used for fairness, this makes DB dogs able to be used again
                printf("Adding a dog A to the list\n");
                break;
            case DB:
                d->dogBs++;
                d->counterDB++;
                d->counterDA = 0; //This makes DA dogs able to enter again
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
int dogdone(dogtype dogToWash)
{
        sem_wait(&lock); // "locks"
        switch(dogToWash)
    {
            case DA:
                d->dogAs--;
                sem_post(&condDogs);
                break;
            case DB:
                d->dogBs--;
                sem_post(&condDogs);
                break;
	    case DO:
                sem_post(&condDogs);
    //No DO case unless a reason to make one arises
    }
    printf("Dog is now done being washed, GO HOME! \n");
    d->curnumbays--;
    sem_post(&condBays);
    sem_post(&lock); // "unlocks"
    return 0;
}
//Called when data clean up is required, destroys locks
// returns 0 for success and -1 for faliure
int dogwash_done()
{
    printf("Initializing dog bay \n");
    free(d);
    d->curnumbays = 0;
    d->totaldogs = 0;
    d->dogAs = 0;
    d->dogBs = 0;
    d->totalbays = 0;
    d->counterDA = 0;
    d->counterDB = 0;
    // Destroy sems
    return 0;
}
