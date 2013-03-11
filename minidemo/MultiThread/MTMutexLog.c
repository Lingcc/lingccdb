#include <pthread.h>
#include <stdio.h>
pthread_mutex_t LogLock = PTHREAD_MUTEX_INITIALIZER;
char* LogFileName= "test.log";
void* func_tid0( void* a) {
  int i;
  for(i=0; i < 50; i++ ) {
    pthread_mutex_lock(&LogLock);
    fprintf((FILE*)a, "write to log by thread0:%d\n", i);
    pthread_mutex_unlock(&LogLock);
  }
}

void* func_tid1(void* a) {
  int i;
  for(i=0; i < 50; i++ ) {
    pthread_mutex_lock(&LogLock);
    fprintf((FILE*)a, "write to log by thread1:%d\n", i);
    pthread_mutex_unlock(&LogLock);
  }
}
int main()  {
  pthread_t tid0, tid1;
  FILE* fp=fopen(LogFileName, "wb+");
  pthread_create(&tid0, NULL, func_tid0, (void*) fp );
  pthread_create(&tid1, NULL, func_tid1, (void*) fp );
  void* ret;
  pthread_join(tid0, &ret);
  pthread_join(tid1, &ret);
}
