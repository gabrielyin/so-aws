#include <pthread.h>
#include <stdio.h>

struct c {
  int saldo;
};

typedef struct c conta;

conta from, to;
int valor;
pthread_mutex_t mutex;

struct transfers {
  conta from;
  conta to;
  int valor;
};

void *transferencia(void *arg) {
  pthread_mutex_lock(&mutex);
  if (from.saldo >= valor) {
    from.saldo -= valor;
    to.saldo += valor;
    printf("Tranferencia realizada com sucesso\n");
    printf("Saldo da conta 1 %d\n", from.saldo);
    printf("Saldo da conta 2 %d\n", to.saldo);
  } else {
    printf("Saldo insuficiente\n");
  }
  pthread_mutex_unlock(&mutex);
  return 0;
}

int main(void) {
  pthread_t threads[10];

  from.saldo = 100;
  to.saldo = 100;

  printf("Transferindo 10 para a conta 2\n");
  valor = 10;

  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, transferencia, NULL);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex);
  return 0;
}
