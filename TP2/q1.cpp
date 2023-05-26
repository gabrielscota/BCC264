#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define READ 0
#define WRITE 1

void showMenu()
{
  printf("\nAperte uma das opçoes abaixo e tecle enter\n");
  printf("[+] para incrementar 1000 UDs.\n");
  printf("[-] para decrementar 1000 UDs.\n");
  printf("[s] para ver o saldo.\n");
  printf("[k] para finalizar a execucao.\n");
}

int main()
{
  showMenu();

  int saldo[2];
  int opcao[2];
  int caractere = 0;

  if (pipe(saldo) < 0 || pipe(opcao) < 0)
  {
    printf("Erro ao criar pipe\n");
    exit(1);
  }

  int aux = 0;
  if (write(saldo[WRITE], &aux, sizeof(int)) == -1)
  {
    printf("Erro ao escrever no pipe\n");
    exit(1);
  }

  pid_t pidPai = getpid();
  pid_t filho1 = fork();
  if (filho1 < 0)
  {
    printf("Erro ao criar fork\n");
    exit(1);
  }
  fflush(stdin);

  pid_t filho2 = -1;
  if (getpid() == pidPai)
  {
    filho2 = fork();
    if (filho2 < 0)
    {
      exit(1);
    }
    if (filho2 == 0)
    {
      filho1 = -1;
    }
  }

  if (getpid() == pidPai)
  {
    int balance;
    while (caractere != 107)
    {
      do
      {
        caractere = (int)getchar();
      } while ((caractere != 43) && (caractere != 45) && (caractere != 107) && (caractere != 115));

      if (caractere == 115)
      {
        read(saldo[READ], &balance, sizeof(int));
        printf("\n> PID: %d", getpid());
        printf("\n> Saldo: %d UDs\n\n", balance);
        write(saldo[WRITE], &balance, sizeof(int));
      }
      else
      {
        write(opcao[WRITE], &caractere, sizeof(int));
      }

      if (caractere == 107)
      {
        kill(filho1, SIGKILL);
        kill(filho2, SIGKILL);
        kill(getpid(), SIGKILL);
        exit(0);
      }
    }
  }
  else if (filho1 == 0)
  {
    int operacao;
    int balance;
    do
    {
      read(opcao[READ], &operacao, sizeof(int));

      if (operacao == 43)
      {
        printf("\n> PID: %d", getpid());
        printf("\n> Incrementado 1000 UDs ao saldo.\n\n");
        read(saldo[READ], &balance, sizeof(int));
        balance += 1000;
        write(saldo[WRITE], &balance, sizeof(int));
      }
      else
      {
        write(opcao[WRITE], &operacao, sizeof(int));
      }
    } while (operacao != 107);
  }
  else if (filho2 == 0)
  {
    int operacao;
    int balance;
    do
    {
      read(opcao[READ], &operacao, sizeof(int));

      if (operacao == 45)
      {
        printf("\n> PID: %d", getpid());
        printf("\n> Decrementado 1000 UDs do saldo.\n\n");
        read(saldo[READ], &balance, sizeof(int));
        balance -= 1000;
        write(saldo[WRITE], &balance, sizeof(int));
      }
      else
      {
        write(opcao[WRITE], &operacao, sizeof(int));
      }
    } while (operacao != 107);
  }

  return 0;
}
