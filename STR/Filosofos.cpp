#include <iostream>
#include <thread>
#include <semaphore.h>
using namespace std;

#define N 5
#define PENSANDO 'P'
#define FAMINTO 'F'
#define COMENDO 'C'
#define ESQUERDA (id+4) %N // Sem uso
#define DIREITA (id+1) %N
char estado[N];
sem_t Garfos[N];
sem_t mutexAtualiza; 

void sleep(int t){
    std::this_thread::sleep_for(std::chrono::seconds(t));
}
void imprimeEstado(){
    for (int i = 0; i < N; i++){
        cout << estado[i] << ',';
    }
    for (int i = 0; i < N; i++){
        int estGarfo;
        sem_getvalue(&Garfos[i], &estGarfo);
        char c = estGarfo ? 'L':'O';
        cout << c;
        cout << (i == 4? '\n' : ',');
    }
    cout.flush();
}
void pensar (int id)
{
    int r = (rand() % 10 + 1);
    sleep( r );
    sem_wait(&mutexAtualiza);
    estado[id] = FAMINTO;
    imprimeEstado();
    sem_post(&mutexAtualiza);
}
void comer ()
{
    int r = (rand() % 10 + 1);
    sleep( r );
}

void pegarGarfo(int id){
    while(1){
        sem_wait(&mutexAtualiza);
        if(sem_trywait(&Garfos[id]) == 0){
            if(sem_trywait(&Garfos[DIREITA]) == 0){
                break;
            }
            sem_post(&Garfos[id]);
        }
        sem_post(&mutexAtualiza);
    }
    
    
    estado[id] = COMENDO;
    imprimeEstado();
    sem_post(&mutexAtualiza);

}
void soltarGarfo(int id){
    sem_wait(&mutexAtualiza);
    sem_post(&Garfos[id]);
    sem_post(&Garfos[DIREITA]);
    estado[id] = PENSANDO;
    imprimeEstado();
    sem_post(&mutexAtualiza);

}

void filosofoFunction(int id) {
    while (1)
    {  
        pensar(id);
        pegarGarfo(id);
        comer();
        soltarGarfo(id);
    }
    
}

int main() {
    std::thread filosofos[N];
    sem_init(&mutexAtualiza,0,1);
    for (int i =0; i<N; i++){
        estado[i] = 'P';
        sem_init(&Garfos[i],0,1);
        filosofos[i] = std::thread(filosofoFunction, i);
    }
    for (int i = 0; i < N; ++i) {
        filosofos[i].join();
    }
    return 0;
}
