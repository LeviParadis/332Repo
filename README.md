#Thread and Concurrency Program
This program is an example of using Pthread and POSIX locks and threads to solve a concurrency problem. This was an assignment for my Operating
System Concepts class.

###The Problem
We need to create a dog wash with a limited number of dogwash bays. Each dogwash bay can serve one dog at a time. Furthermore there
is also 3 types of dogs that will be served DA,DB, and DC. The DA and DB dogs can not be in the facility at the same time. This 
means that if a DA is being washed and a DB shows up it will have to wait for DA to be finished. The complete rules are as follows:

1. DAs and DBs will never be washed at the same time. If a DA is in the wash bay a DB will have to wait and vice versa.
2. Only one dog can be washed in a dog wash bay at a time.
3. Neither DAs nor DBs nor DOs should have to wait indefinitely, measures have been taken to prevent this in the program
4. The solution is also meant to be effecient while utilizing concurrency

###The Solution
I created different programs that are very similar. The first program solves this problem using Pthread mutex locks and condition 
variables.

The second solution uses POSIX semaphores to solve the exact same problem.

The first solution can be found in the files dogwashsynch.c and dogwashtest.c along with the header file dogwashsynch.h, if you want
to run the program you simply need to download the files (along with my Makefile) and run the "make" command. 

The second solution can be found in PartC/dogwashsynch.c and dogwashtest.c. Running this is exactly the same as the first

####Questions
Emailing me at levi.paradis@usask.ca
