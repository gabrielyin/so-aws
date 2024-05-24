#include <pthread.h>
#include <stdio.h>

struct c {
  int saldo;
};

typedef struct c conta;

conta from, to;
int valor;
pthread_mutex_t mutex;

void *transferenciaFromTo(void *arg) {
  pthread_mutex_lock(&mutex);
  printf("\n-----TRANSFERENCIA 10,00 FROM TO-----\n");
  if (from.saldo >= valor) {
    from.saldo -= valor;
    to.saldo += valor;
    printf("\nTranferencia realizada com sucesso\n");
    printf("Saldo da conta FROM %d\n", from.saldo);
    printf("Saldo da conta TO %d\n", to.saldo);
  } else {
    printf("Saldo insuficiente\n");
  }
  pthread_mutex_unlock(&mutex);
  return 0;
}

void *transferenciaToFrom(void *arg) {
  pthread_mutex_lock(&mutex);
  printf("\n-----TRANSFERENCIA 10,00 TO FROM-----\n");
  if (to.saldo >= valor) {
    to.saldo -= valor;
    from.saldo += valor;
    printf("\nTranferencia realizada com sucesso\n");
    printf("Saldo da conta FROM %d\n", from.saldo);
    printf("Saldo da conta TO %d\n", to.saldo);
  } else {
    printf("Saldo insuficiente\n");
  }
  pthread_mutex_unlock(&mutex);
  return 0;
}

int main(void) {
  pthread_t threads[100];

  from.saldo = 1000;
  to.saldo = 1000;

  valor = 10;

  for (int i = 0; i < 60; i++) {
    pthread_create(&threads[i], NULL, transferenciaFromTo, NULL);
  }

  for (int i = 0; i < 40; i++) {
    pthread_create(&threads[i], NULL, transferenciaToFrom, NULL);
  }

  for (int i = 0; i < 100; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex);
  return 0;
}
