#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>

int main() {

int fd[2];

if (pipe(fd) == -1) {
printf("Erro ao abrir pipe");
}

int id = fork();

if (id < 0) {
printf("Erro\n");
} else if (id == 0) {
close(fd[0]);
char mensagemFilho[100];
printf("[Processo filho] Digite a sua mensagem: ");
fgets(mensagemFilho, sizeof(mensagemFilho), stdin);
write(fd[1], &mensagemFilho, strlen(mensagemFilho) + 1);
close(fd[1]);
} else {
wait(NULL);
close(fd[1]);
char mensagemPai[101];
read(fd[0], &mensagemPai, sizeof(mensagemPai));
printf("[Processo pai]: %s\n", mensagemPai);;
close(fd[0]);
}
return 0;
}
