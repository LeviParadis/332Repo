/* 
 * File:   main.c
 * Author: ldp343
 *
 * Created on November 5, 2015, 1:06 PM
 */
#include "dogwashsynch.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_DOGS 10
void *dog(void* d){
 dogwash_init(11,d);
  newdog(DA,d); 
 //Sleep 
  dogdone(DA,d);
  pthread_exit(NULL);
}
/*
 * 
 */
int main(int argc, char** argv) {
    dogwash *dogWashTrack = malloc(sizeof(dogwash));
    pthread_t p[NUM_DOGS]; // TODO: Make this a thread of multiple dogs
    int rc;
    long i;
    for(i =0; i < NUM_DOGS; i++){
    rc = pthread_create(&p[i],NULL, dog, (void*)dogWashTrack);
    if (rc){
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(-1);
    }
    }
    pthread_exit(NULL);
}

