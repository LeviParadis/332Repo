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
#define NUM_DOGS 11




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
int main(int argc, char** argv) {
    srand(time(NULL));
    pthread_t p[NUM_DOGS];
    dogtype mixBreeds[] = {DA,DB,DO};
    int rc;
    dogwash_init(5);
    //copying static defined array to the dogtype array;
    long i;
    for(i =0; i < NUM_DOGS; i++){
        rc = pthread_create(&p[i],NULL, dog, (void*) mixBreeds[(rand() % 3) - 1]);
    
        if (rc){
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
        }
    }
    pthread_exit(NULL);
}

