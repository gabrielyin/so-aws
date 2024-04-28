#include <pthread.h>
#include <stdio.h>
#define ROWS 3
#define COLS 3

int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {1, 2, 3}};
int vector[ROWS] = {7, 1, 1};
int result[ROWS] = {0, 0, 0};

void *multiply(void *arg) {
  int i = *((int *)arg);

  for (int l = 0; l < COLS; l++) {
    result[i] += matrix[i][l] * vector[i];
  }

  return NULL;
}

int main() {
  pthread_t threads[ROWS];
  int i, thread_args[ROWS];

  for (i = 0; i < ROWS; i++) {
    thread_args[i] = i;
    pthread_create(&threads[i], NULL, multiply, (void *)&thread_args[i]);
  }

  for (i = 0; i < ROWS; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("--- Resultado ---\n");
  for (i = 0; i < ROWS; i++) {
    printf("[%d]: %d\n", i, result[i]);
  }

  return 0;
}
