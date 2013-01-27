#include <stdio.h>
#include <pthread.h>

/** Practice: POSIX interface for multithread in C language
 *
 *
 *
 */

void* do_loop(void* data) {
  /* counter, to print numbers */
  int i;
  /** counter for delay */
  int j;
  /** Thread identifying number */
  int me=*((int*)data);

  for(i=0; i < 10; i++) {
    /* delay loop */
    /* TODO: can we use sleep() here, not just a loop */
    for(j=0; j < 5000; j++);
    printf("'%d'-Got '%d'\n", me, i);
  }
  /** Terminate the thread */
  /* TODO: what will happen if do not call pthread_exit */
  pthread_exit(NULL);
}

int main(int argc, char* argv[])  {
  int thr_id; /** Thread ID for the newly created thread */

  pthread_t p_thread; /* thread's structure */

  /* thread 1 identifying number */
  int a = 1;

  /* thread 2 identifying number */
  int b = 2;

  /** Create a new thread to run do_loop() */

  /** do_loop will run as a main function of the new thread.
   * the thread will start running by call the do_loop function.
   * There will be 2 call-stacks for these 2 threads.
   */
  thr_id = pthread_create (&p_thread, NULL, do_loop, (void*)&a);

  /** run do_Loop() in the main thread */
  do_loop((void*)&b);


  return 0;


}
