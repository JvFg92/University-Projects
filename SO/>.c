#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Pilha{
    int data[5];
    int top;
};

void init(struct Pilha *pilha) {
    pilha->top = -1;
}

int isEmpty(struct Pilha *pilha) {
    return (pilha->top == -1);
}

int isFull(struct Pilha *pilha) {
    return (pilha->top == 5 - 1);
}

int desempilhar(struct Pilha *pilha) {
    if (isEmpty(pilha)) {
        printf("A pilha está vazia. Não é possível desempilhar elementos.\n");
        return -1; // Valor de erro
    } else {
        return pilha->data[pilha->top--];
    }
}

void empilhar(struct Pilha *pilha, int item) {
    if (isFull(pilha)) {
        printf("A pilha está cheia. Não é possível adicionar mais elementos.\n");
    } else {
        pilha->data[++pilha->top] = item;
    }
}

void printStack(struct Pilha *pilha) {
    if (isEmpty(pilha)) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Elementos da pilha:\n");
        for (int i = pilha->top; i >= 0; i--) {
            printf("%d\n", pilha->data[i]);
        }
    }
}

void mensagem(void){
    printf("Gerador de pilha:\n");
    printf("Digite 0 para parar o programa!\n");
    printf("Digite 1 para inserir um elemento!\n");
    printf("Digite 2 para remover um elemento!\n");
    printf("Digite 3 para imprimir a pilha!\n");
}

int main(){
    void mensagem(void);
    struct Pilha pilha;
    init(&pilha);
    int a=-1;
    bool aux=true;

    while(aux==true){
        
        mensagem();
        scanf("%d",&a);

        switch (a){
        case 0:
            printf("Encerrando!\n");
            aux=false;
            break;
        case 1:
            int b;
            printf("Digitie o número a ser inserido:\n");
            scanf("%d",&b);
            empilhar(&pilha,b);
            break;
        case 2:
            printf("Desempilhando ultimo elemento!\n");
            desempilhar(&pilha);
            break;
        case 3:
            printStack(&pilha);
            break;
        
        default:
            break;
        }
    }

    while(!isEmpty(&pilha)) desempilhar(&pilha);
    
    return 0;
}