#include <iostream>
#include <stdlib.h>

using namespace std;

//Definição de Classe:
class memory{
    public:
    
        memory();
    // Define operação de retorno/busca da memória:

        long double get_result(){
            return resultado;
        }

    // Define valor inicial da memória como primeiro valor inserido:

        void set_result(double a){
            resultado=a;
        }

    //Define operações matemáticas da calculadora em acesso publico, utilizando o resultado pré definido como primeiro valor:

        //Soma:
        long double soma(long double b);

        //Subtração:
        long double subtracao(long double b);

        //Multiplicação:
        long double multipicacao(long double b);

        //Divisão:
        long double divisao(long double b);

    private:
    // Priva a memória do acesso e manipulação direta:

        long double resultado;

};

//Prototipação das funções e padronização da memória = 0:

    memory::memory(){
        resultado=0;
    }

    //Soma:
    long double memory::soma(long double b){
        resultado+=b;
        return resultado;
    }

    //Subtração:
    long double memory::subtracao(long double b){
        resultado-=b;
        return resultado;
    }

    //Multiplicação:
    long double memory::multipicacao(long double b){
        resultado*=b;
        return resultado;
    }

    //Divisão:
    long double memory::divisao(long double b){
        resultado/=b;
        return resultado;
    }

// Definição Função Principal:
int main(void){
//Definições e Variaveis:
    int calculadora(void);
    int cont=0;

   while (cont!=1){
    cont=calculadora();
   } 
    cout<<":)"<<endl;   
    return 0;
}

// Função para ler um número e retorná-lo:
long double recebe_numero(void) {
    long double num;
    cin >> num;

    while (cin.fail()) {
        cin.clear(); // Limpa o estado de erro de cin
        cin.ignore(10000, '\n'); // Ignora o que foi digitado até a quebra de linha
        cout << "Entrada inválida :(! Digite um número válido." << endl;
        cin >> num;
    }

    return num;
}

//Função que realiza o código em si, e que evita erros não especificos:
int calculadora(void){

    //Instancendo a calculadora:
    memory *memoria= new memory;
   
    bool parada = false;
    long double a=0,b=0;
    char operacao;

//Inicia o Looping de funcionamento da calculadora:   
    while (parada==false){

        //Mostra o valor da memória:
        cout << "Valor armazenado: "<< memoria->get_result()<<endl;

        //Separação:
        cout <<"============================"<<endl;

        //Condição de verificação de inicialização / reinicialização da calculadora:
        if (memoria->get_result()==0){

            /*Inicialização com finalização/Sempre que o resutado salvo na memória for = 0 a operação 
            padrão torna-se a entrada de um novo número*/

            cout<<"Para Sair agora digite [S]. Para continuar tecle um caractere qualquer e dê 'ENTER':"<<endl;
            cin>>operacao;
            if((operacao=='s')or(operacao=='S')){
                cout<<"Encerrando..."<<endl;
                delete memoria;
                parada=true;
                return 1;
            }

            cout<<"Insira o primeiro número:"<<endl;
            a=recebe_numero();
            memoria->set_result(a);
        }
               
        //Escolha de operação:
        cout << "Escolha a operação: Soma:[+], Subtração[-], Multiplicação:[*], Divisão[/], Limpar[C], Sair[S]:\nTecle 'espaço' e insira um número:"<<endl;
        cin >> operacao;

        //Para o caso de limpeza ou saida, padroniza o caractere para utilização:
        if((operacao=='c') or (operacao=='s')) operacao=toupper(operacao);

        //Separação:
        cout <<"============================"<<endl;

        //Calcula as operações:
        switch(operacao){
            case '+':
                b=recebe_numero();
                cout<<memoria->get_result()<<"+ "<<b<<endl;
                cout<<"Seu resultado é = "<<memoria->soma(b)<<endl;
                break;

            case '-':
                b=recebe_numero();
                cout<<memoria->get_result()<<"- "<<b<<endl;
                cout<<"Seu resultado é = "<<memoria->subtracao(b)<<endl;
                break;

            case '*':
                b=recebe_numero();
                cout<<memoria->get_result()<<"* "<<b<<endl;
                cout<<"Seu resultado é = "<<memoria->multipicacao(b)<<endl;
                break;

            case '/':
                b=recebe_numero();
                if(b==0){
                    cout<<"Não é Possível dividir por 0. Escolha outra operação ou valor"<<endl;
                    break;
                }
                cout<<memoria->get_result()<<"/ "<<b<<endl;
                cout<<"Seu resultado é = "<<memoria->divisao(b)<<endl;
                break;

            case 'C':
                cout<<"Limpando Memória... "<<endl;
                memoria->set_result(0);
                break;

            case 'S':
                cout<<"Limpando Memória... "<<endl;
                memoria->set_result(0);
                cout<<"Encerrando..."<<endl;
                delete memoria;
                parada=true;
                return 1;
                break;

            default:
                cout<<"Operação invalida :( , tente novamente."<<endl;
                break;
        }

        //Separação:
        cout <<"============================"<<endl;

    }  
    
    return 0;   
}