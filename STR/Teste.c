#include <stdio.h>

// Função para realizar uma mudança cíclica nos elementos do vetor para a esquerda
void round_robin(int *vet, int num_intens) {
    int temp = vet[0]; // Armazena o primeiro elemento

    // Move cada elemento para a posição anterior
    for (int i = 0; i < num_intens - 1; i++) {
        vet[i] = vet[i + 1];
    }

    // Move o primeiro elemento para a última posição
    vet[num_intens - 1] = temp;
}

int main() {
    int vet[5] = {1, 2, 3, 4, 5};
    int num_intens = sizeof(vet) / sizeof(vet[0]); // Tamanho do vetor

    // Imprime o vetor original
    for (int i = 0; i < num_intens; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    // Rotaciona o vetor e imprime em cada iteração
    for (int j = 0; j < num_intens; j++) {
        round_robin(vet, num_intens); // Chama a função round_robin para realizar a mudança cíclica

        // Imprime o vetor modificado
        for (int i = 0; i < num_intens; i++) {
            printf("%d ", vet[i]);
        }
        printf("\n");
    }

    return 0;
}
