#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<int> sort(vector<int> vetor) {
    int aux;
    for(int i = 0; i < vetor.size() - 1; i++) {
        for(int j = 0; j < vetor.size() - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    return vetor;
}

int main() {
    int repeticao=1000;
    vector<int> vet = {13, 2, 5, 6, 7, 4, 3, 1, 20, 9, 12, 19, 0, 736, 90};
    cout << "Vetor original:" << endl;
    for (int num : vet) {
        cout << num << " ";
    }
    cout << endl;

    auto inicio = chrono::high_resolution_clock::now();

    for (int j = 0; j < repeticao; j++) {
        vector<int> sorted = sort(vet);
        

    auto resultado = chrono::high_resolution_clock::now() - inicio;
    long long microseconds = chrono::duration_cast<chrono::microseconds>(resultado).count();
    cout << microseconds << endl;

    }


    return 0;
}