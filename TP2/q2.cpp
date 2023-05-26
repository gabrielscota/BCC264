#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

#define NUMTHREADS 3

pthread_t threads[NUMTHREADS];
int balance = 0;

void *thread_show_balance(void *arg);
void *thread_add_balance(void *arg);
void *thread_subtraction_balance(void *arg);

void showMenu()
{
  printf("\nAperte uma das opçoes abaixo e tecle enter\n");
  printf("[+] para incrementar 1000 UDs.\n");
  printf("[-] para decrementar 1000 UDs.\n");
  printf("[s] para ver o saldo.\n");
  printf("[k] para finalizar a execucao.\n");
}

int main(int argc, char **argv)
{
  showMenu();

  int i;
  int opcao = 0;

  while (opcao != 107)
  {
    opcao = (int)getchar();

    if (opcao == 115)
    {
      pthread_join(threads[0], NULL);
      pthread_join(threads[1], NULL);
      pthread_join(threads[2], NULL);
      pthread_create(&(threads[0]), NULL, thread_show_balance, NULL);
    }
    else if (opcao == 43)
    {
      pthread_join(threads[1], NULL);
      pthread_create(&(threads[1]), NULL, thread_add_balance, NULL);
    }
    else if (opcao == 45)
    {
      pthread_join(threads[2], NULL);
      pthread_create(&(threads[2]), NULL, thread_subtraction_balance, NULL);
    }
    else if (opcao == 107)
    {
      pthread_detach(threads[0]);
      pthread_detach(threads[1]);
      pthread_detach(threads[2]);
    }
    else
    {
      continue;
    }
  }

  return 0;
}

void *thread_show_balance(void *arg)
{
  pid_t tid;
  tid = syscall(SYS_gettid);
  printf("\n> TID: %d", tid);
  printf("\n> Saldo: %d UDs\n\n", balance);
  pthread_exit(0);
}

void *thread_add_balance(void *arg)
{
  pid_t tid;
  tid = syscall(SYS_gettid);
  printf("\n> TID: %d", tid);
  printf("\n> Incrementado 1000 UDs ao saldo.\n\n");
  balance += 1000;
  pthread_exit(0);
}

void *thread_subtraction_balance(void *arg)
{
  pid_t tid;
  tid = syscall(SYS_gettid);
  printf("\n> TID: %d", tid);
  printf("\n> Decrementado 1000 UDs do saldo.\n\n");
  balance -= 1000;
  pthread_exit(0);
}