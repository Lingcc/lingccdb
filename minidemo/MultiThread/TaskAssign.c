#include <unistd.h>
#include <pthread.h>
#include <stdio.h>


void*  print_i(void* ptr_i) {

  pthread_t tid= pthread_self();


  printf("Current Thread id=%d, i=%d\n", (unsigned long)tid, *(int *)ptr_i);

  sleep(10);

  pthread_exit(NUL
}

int main() {
  
  int a[10]={1,2,3,4,5,6,7,8,9,10};

  int i = 0;
  for( ; i < 10; i++) {
  
    pthread_t new_tid;
    if( pthread_create(&new_tid, NULL, print_i, &i) ) {
      printf("Can not create the %dth thread", i);
    } else {
      printf("create thread %d\n", i);
    }
  }

  return 0;


}
