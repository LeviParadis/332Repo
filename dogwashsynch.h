/* 
 * File:   dogwashsynch.h
 * Author: ldp343
 *
 * Created on November 5, 2015, 1:54 PM
 */

#ifndef DOGWASHSYNCH_H
#define	DOGWASHSYNCH_H

typedef enum {DA,DB,DO} dogtype;

typedef struct dogwash{
    int curnumbays;
    int totaldogs;
    int dogAs;
    int dogBs;
    int dogOs;
    int totalbays;
    int arrayCursor;
} dogwash;


#endif	/* DOGWASHSYNCH_H */

