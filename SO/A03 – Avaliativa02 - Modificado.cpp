/*********************************************************************************************************************************************************

Trabalho de Sistemas Operacionais: Codigo de simulacao do algoritmo LRU

*********************************************************************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

//Funcao auxiliar para imprimir linha de separacao:
void linha();

//Funcao auxiliar para verificar se uma pagina esta na memoria, caso esteja retorna sua posicao
int verifica_memoria(vector<int> memory, int page, int capacity);

//Funcao auxiliar para adequar o algoritmo a cada atualizacao de pagina:
void modifica_memoria(vector<int> &memory, vector<int> &T, int page, int cicle);

int main(){
    //Declaracao de variaveis:
    int page_faults = 0, capacity = 4, verificador=-1,pagina;
    vector<int> pages; //7 2 4 0 3 1 7 0 2 0 3 1 2 8 3 7
    vector<int> memory;
    vector<int> T;

    //Insere as paginas no vetor pages:
    cin>>pagina;
    pages.push_back(pagina);
    while(!cin.fail()){
        cin>>pagina;
        if(!cin.fail())pages.push_back(pagina);
    }

    //Indica as paginas utlilizadas, seu total e a capacidade de armazenamento:
    cout << "Pages Process [ ";
    for (auto i = pages.begin(); i != pages.end(); ++i) cout << *i << " ";
    cout << " ]"<<endl;

    cout << "Number of pages = " << pages.size()-1 << endl;
    cout << "Capacity = " << capacity << endl;
    cout << endl;
    linha();

    //Executa o Algoritmo LRU:
    for(int i = 0; i < pages.size() ; i++){

        //Indica o ciclo de execucao:
        cout<<"Ciclo = "<< i << " ";
        cout << "- Pagina Requerida -> " <<pages[i] << endl;

        //Verifica se a pagina chamada ja está na memoria:
        verificador=verifica_memoria(memory, pages[i], memory.size());
        if(verificador!=-1){
            cout<<"Pagina "<<pages[i]<<" encontrada na posicao "<< verificador <<endl;
            //Modifica LRU:
            T[verificador] = i;
        }
        
        //Verifica se ainda ha espaco disponivel na memoria
        else if(memory.size()<capacity){
            cout<<"Page Fault - Capacidade OK"<<endl;
            memory.push_back(pages[i]);
            T.push_back(i);
            page_faults++;
        }

        //Caso a memoria ja tenha atingido seu limite aplica o algoritmo LRU e realiza a substituicao
        else{
            cout<<"Page Fault - acima capacidade"<<endl;
            modifica_memoria(memory,T,pages[i],i);
            page_faults++;
        }

        //Mostra as paginas salvas na memoria
        cout<<"Pages Memory [   ";
        for(int c = 0; c < memory.size(); c++)cout<<memory[c]<<"->T="<<T[c]<<"    ";
        cout<<"]"<<endl;
        linha();

   }
    //Mostra quantas paginas deixaram de ser usadas
    cout << "Total Page Faults: " <<page_faults<< endl;
    return 0;
}

//DESENVOLVIMENTO DAS FUNCOES
void linha(){
    cout <<"----------------------------------------------------------"<< endl;
}

int verifica_memoria(vector<int> memory, int page, int capacity){
    for(int i=0; i<capacity; i++){
        if(memory[i]==page) return i;
    }
    return -1;
}

void modifica_memoria(vector<int> &memory, vector<int> &T, int page, int cicle){
    int lru = memory[0];
    int pos_lru = 0;

    for(int i=0; i<memory.size();i++){
        if(T[i] < T[pos_lru]){
            lru = memory[i];
            pos_lru = i;
        }
    }

    cout<<"Elimina a pagina LRU "<<lru<<endl;
    cout<<"Insere a pagina = "<<page<<endl;
    memory[pos_lru] = page;
    T[pos_lru] = cicle;
}