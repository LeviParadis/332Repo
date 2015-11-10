/* 
 * File:   main.c
 * Author: ldp343
 *
 * Created on November 5, 2015, 1:06 PM
 */
#include "dogwashsynch.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_DOGS 10

static const dogtype mixBreeds[] = {DA,DB,DO};

typedef struct myarg{
    dogwash *dogWashStats;
    dogtype dogTypeArray[NUM_DOGS];
} myarg;
void *dog(void* args){
  myarg *d = (myarg *) args;
  //filling array with dogs
  newdog(mixBreeds[(rand() % 3) - 1],d->dogWashStats); 
  sleep(10); 
  dogdone(mixBreeds[(rand() % 3) - 1],d->dogWashStats);
  pthread_exit(NULL);
}
/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    pthread_t p[NUM_DOGS]; // TODO: Make this a thread of multiple dogs
    int rc;
    myarg arglist;
    arglist.dogWashStats = malloc(sizeof(dogwash));
    dogwash_init(5,arglist.dogWashStats);
    //copying static defined array to the dogtype array;
    memcpy(arglist.dogTypeArray,mixBreeds,sizeof(arglist.dogTypeArray));
    long i;
    for(i =0; i < NUM_DOGS; i++){
        rc = pthread_create(&p[i],NULL, dog, &arglist);
    
        if (rc){
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
        }
    }
    pthread_exit(NULL);
}

