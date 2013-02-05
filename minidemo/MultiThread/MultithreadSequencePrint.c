#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

// TODO: Can this problem be solved using semaphore?


#define NUM 3
#define DEBUG 1

int n=0;
pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t qready = PTHREAD_COND_INITIALIZER;


// After main function, there are totally 3 thread running into thread_func
//
void* thread_func(void* arg) {
  int param = (int) arg;
  
  // The char will be printed
  char c='A'+param;
  int ret, i=0;

  // Each thread print 10 times.
  for(; i < 10; i++) {

    // use mylock to get a lock, other threads who want to use mylocal should
    // wait it to be unlocked later.
    pthread_mutex_lock(&mylock); 

#if DEBUG
    printf("thread %d get the lock\n", param);
#endif

    while(param != n) {

#if DEBUG
      printf("thread %d waiting\n", param);
#endif
      // wait for the qready cond. during the wait, and release mylock
      // After the qready is set, relock the mutex in current thread.
      ret = pthread_cond_wait(&qready, &mylock);

      if(ret == 0) {
#if DEBUG
        printf("thread %d wait success\n", param);
#endif
      } else {
#if DEBUG
        printf("thread %d wait failed: %s\n", param, strerror(ret));
#endif
      }
    }
    printf("%c ",c);
    n = (n+1)%NUM;

    // release the lock
    pthread_mutex_unlock(&mylock);
#if DEBUG
    printf("thread %d release the lock\n", param);
#endif

    // broadcast the condition, and other thread knows that the cond is 
    // saticsfied.
    pthread_cond_broadcast(&qready);
  }
  return (void*) 0;
}


int main( int argc, char** argv) {

  int i =0, err;
  pthread_t tid[NUM];
  void* tret;

  for(; i<NUM; i++) {
    // Start 3 threads, each run into thread_func, and the param is 1,2,3
    err = pthread_create(&tid[i], NULL, thread_func, (void*)i); 
    if(err != 0) {
      printf("thread_create error:%s\n", strerror(err));
      exit(-1);
    }

  }

  for(i=0; i < NUM; i++) {
    // wait for all thread to finish, use tret to get the return value of
    // the tid[i] thread.
    err = pthread_join(tid[i], &tret);
    if(err != 0) {
      printf("can not join with thread %d:%s\n", i, strerror(err));
      exit(-1);
    }
  }
  printf("\n");
  return 0;
}

