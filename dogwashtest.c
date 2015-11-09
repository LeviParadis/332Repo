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
#include <unistd.h>
#define NUM_DOGS 10

typedef struct arglist{
	dogwash *dogWashTrack;
	int dogtypes[NUM_DOGS]= {DA,DA,DA,DB,DB,DO,DB,DA,DA,DO};
}
void *dog(void* d, void* dogtype type){
 dogwash_init(11,d);
  newdog(DA,d); 
  sleep(10); 
  dogdone(DA,d);
  pthread_exit(NULL);
}
/*
 * 
 */
int main(int argc, char** argv) {
    pthread_t p[NUM_DOGS]; // TODO: Make this a thread of multiple dogs
    int rc;
    arglist.dogWashTrack = malloc(sizeof(dogwash));
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

