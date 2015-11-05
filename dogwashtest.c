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

void *dog(){
  newdog(DA);  
  
  return NULL;
}
/*
 * 
 */
int main(int argc, char** argv) {
    dogwash_init(10);
    pthread_t p;
    int rc;
    dogtype dog1;
    
    
    rc = pthread_create(&p,NULL, dog,&dog1);
    
    return (EXIT_SUCCESS);
}

