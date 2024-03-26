#include <pthread.h>
#include <stdio.h>

typedef struct {
  int time;
  int direction;
} Person;

int globalTime = 0;
int direction = 0;

void *person(void *arg) {
  Person *person = (Person *)arg;

  if (direction != person->direction) {
    
  }

  return NULL;
}

int main() {

  FILE *file = fopen("entrada.txt", "r");
  if (file == NULL) {
    printf("Erro ao abrir arquivo de entrada.\n");
    return 1;
  }

  int amountPeople;
  if (fscanf(file, "%d", &amountPeople) != 1) {
    printf("Erro ao ler número de pessoas");
    fclose(file);
    return 1;
  }

  Person people[amountPeople];

  for (int i = 0; i < amountPeople; i++) {
    if (fscanf(file, "%d %d", &people[i].time, &people[i].direction) != 2) {
      printf("Erro ao ler informações da pessoa %d.\n", i + 1);
      fclose(file);
      return 1;
    }
  }

  pthread_t threads[amountPeople];
  for (int i = 0; i < amountPeople; i++) {
    if (pthread_create(&threads[i], NULL, person, &people[i]) != 0) {
      printf("Erro ao criar thread para a pessoa %d.\n", i + 1);
      fclose(file);
      return 1;
    }
  }

  for (int i = 0; i < amountPeople; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      printf("Erro ao aguardar thread da pessoa %d.\n", i + 1);
      fclose(file);
      return 1;
    }
  }

  printf("%d", globalTime);

  return 1;
}