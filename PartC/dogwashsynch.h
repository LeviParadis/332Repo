/* 
 * File:   dogwashsynch.h
 * Author: ldp343
 *
 * Created on November 5, 2015, 1:54 PM
 */

#ifndef DOGWASHSYNCH_H
#define	DOGWASHSYNCH_H

typedef enum {DA,DB,DO} dogtype;

    sem_t lock;
    sem_t condBays;
    sem_t condDogs;
    

typedef struct dogwash{
    int curnumbays;
    int totaldogs;
    int dogAs;
    int dogBs;
    int dogOs;
    int totalbays;
} dogwash;


#endif	/* DOGWASHSYNCH_H */

