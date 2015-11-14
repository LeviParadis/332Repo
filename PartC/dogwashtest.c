/* 
 * File:   Semaphore threads
 * Author: Levi Paradis and Emmanuel Boctor
 *
 * Created on November 5, 2015, 1:06 PM
 */
#include "dogwashsynch.h"
#include <pthread.h>
#include <semaphore.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_DOGS 11

static const dogtype mixBreeds[] = {DA,DB,DO};

typedef struct myarg{
    dogwash *dogWashStats;
    dogtype threadID;
} myarg;
void *dog(void* args){
  myarg *d = (myarg *) args;
  d->threadID = mixBreeds[(rand() % 3) - 1];
  //filling array with dogs
  newdog(d->threadID,d->dogWashStats); 
  sleep(10); 
  dogdone(d->threadID,d->dogWashStats);
  pthread_exit(NULL);
}
/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    pthread_t p[NUM_DOGS]; 

    int rc;
    myarg arglist;
    arglist.dogWashStats = malloc(sizeof(dogwash));
    dogwash_init(5,arglist.dogWashStats);
    //copying static defined array to the dogtype array;
    long i;
    for(i =0; i < NUM_DOGS; i++){
        rc = pthread_create(&p[i],NULL, dog, &arglist); // Instead of creating pthreads
        
        if (rc){
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
        }
    }
    pthread_exit(NULL);
}

