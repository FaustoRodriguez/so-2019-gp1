#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	2000

int saldo=0;
pthread_mutex_t locksaldo;

void *PrintHello(void *threadid)
{
   long tid;
   pthread_mutex_lock(&locksaldo);
   int localsaldo = saldo;
   saldo+=localsaldo + 100;
   pthread_mutex_unlock(&locksaldo);
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   printf("forzar perder el cpu");
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   for(t=0;t<NUM_THREADS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }

	for(t=0;t<NUM_THREADS;t++){
		pthread_join(threads[t], NULL);
	}
	printf("Espero 2000 dolares, tengo: %d\n",saldo);
   /* Last thing that main() should do */
   pthread_exit(NULL);
}