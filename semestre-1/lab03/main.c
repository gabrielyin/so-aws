#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int count = 100;

static void *thread(void *arg) {
  count = 40;
  printf("Valor da variável na thread alterado para  %d\n", count);
  return NULL;
}

int main(void) {
  count = 100;
  printf("Valor da variável global no processo pai antes da criação da thread: %d\n", count);

  pthread_t thread1;

  pthread_create(&thread1, NULL, thread, NULL);
  pthread_join(thread1, NULL);

  printf("Valor da variável global no processo pai após a criação da thread: %d\n", count);

  exit(0);
}
