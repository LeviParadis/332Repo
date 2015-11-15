/* 
 * File:   main.c
 * Author: ldp343
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
#define UNFAIR_DOGS 50




void *dog(void* args){
  //filling array with dogs
  newdog(args); 
  sleep(7); 
  dogdone(args);
  pthread_exit(NULL);
}
/*
 * 
 */
int main() {
    srand(time(NULL));
    pthread_t p[NUM_DOGS];
    dogtype mixBreeds[] = {DA,DB,DO};
    int rc;
    dogwash_init(5);
    long i;
    for(i =0; i < NUM_DOGS; i++){
        rc = pthread_create(&p[i],NULL, dog, (void*) mixBreeds[(rand() % 3) - 1]);
    
        if (rc){
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
        }
    }
    void *status;
    //Waiting on other threads
    for (i = 0; i < NUM_DOGS; i++)
    {
        pthread_join(p[i],&status);
    }
    dogdone();
    
    //Next test
    // 1 in 25 chances of a dog B
    dogtype unfairBreeds[] = {DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DA,DB};
    dogwash_init(5);
    pthread_t u[UNFAIR_DOGS];
        for(i =0; i < UNFAIR_DOGS; i++){
        rc = pthread_create(&u[i],NULL, dog, (void*) unfairBreeds[(rand() % 25) - 1]);
    
        if (rc){
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
        }
    }
    
    pthread_exit(NULL);
}

