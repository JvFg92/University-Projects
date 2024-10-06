#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#define N 5
#define PENSAR 0
#define FOME 1
#define COMER 2
#define ESQUERDA (nfilosofo+4)%N
#define DIREITA (nfilosofo+1)%N

void *filosofo(void *num);
void agarraGarfo(int);
void deixaGarfo(int);
void testar(int);

sem_t mutex;
sem_t S[N];
int estado[N];
int nfilosofo[N]={0,1,2,3,4};

void *filosofos(void *num){
    while(1){
        int *i=num;
        sleep(1);
        agarraGarfo(*i);
        sleep(1);
        deixaGarfo(*i);
    }
}

void agarraGarfo(int nfilosofo){
    sem_wait(&mutex);
    estado[nfilosofo]=FOME;
    printf("Filosofo %d tem fome.\n",nfilosofo+1);
    testar(nfilosofo);
    sem_post(&mutex);
    sem_wait(&S[nfilosofo]);
    sleep(1);
}


int main(){
    printf("Hello World\n");
    return 0;
}