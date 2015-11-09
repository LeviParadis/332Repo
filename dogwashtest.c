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
    pthread_t p; // TODO: Make this a thread of multiple dogs
    int rc;
    dogtype dog1;
    rc = pthread_create(&p,NULL, dog, (void*)dogWashTrack);
    
    pthread_exit(NULL);
}

