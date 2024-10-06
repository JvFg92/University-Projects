#include <iostream>
using namespace std;

class Calculadora{
    private:
        float N1;
    public:
        float Add(float num1, float num2);
        float Subtract(float num1, float num2);
        float Product(float num1, float num2);
        float Quocient(float num1, float num2);
        float getResultado();
        void Reset();
};


float recebe_numero() {
    float num;
    cin >> num;
    while (cin.fail()) {
        cin.clear(); // Limpa o estado de erro de cin
        cin.ignore(10000, '\n'); // Ignora o que foi digitado até a quebra de linha
        cout << "Entrada inválida :(! Digite um número válido." << endl;
        cin >> num;
    }
    return num;
}    

int main()
{
    Calculadora *calculadora = new Calculadora;
    float a, b;
    char operation;
    int i = 0;
    do{
        cout << "======================" << endl;
        cout << "Valor Memoria Atual: " << calculadora->getResultado() << endl;
        cout << "======================" << endl;
        cout << "Digite a operação desejada: [+][-][*][/][C][S para sair]";
        cin >> operation;
        if(operation == 'c' || operation == 'C'){
            calculadora->Reset();
            cout << endl;
            i = 0;
        } else {
            if(operation == 's' || operation == 'S'){
                break;
            }
            switch(operation){
                case '+':
                    if(i == 0){
                        cout << "Digite o primeiro número: ";
                        a = recebe_numero();
                        i = 1;
                    } 
                    cout << "Digite o segundo número: ";
                    b = recebe_numero();
                    cout << a << " + " << b << " = " << calculadora->Add(a, b) << endl << endl;
                    break;
                case '-':
                    if(i == 0){
                        cout << "Digite o primeiro número: ";
                        a = recebe_numero();
                        i = 1;
                    } 
                    cout << "Digite o segundo número: ";
                    b = recebe_numero();
                    cout << a << " - " << b << " = " << calculadora->Subtract(a, b) << endl << endl;
                    break;
                case '*':
                    if(i == 0){
                        cout << "Digite o primeiro número: ";
                        a = recebe_numero();
                        i = 1;
                    } 
                    cout << "Digite o segundo número: ";
                    b = recebe_numero();
                    cout << a << " * " << b << " = " << calculadora->Product(a, b) << endl << endl;
                    break;
                case '/':
                    if(i == 0){
                        cout << "Digite o primeiro número: ";
                        a = recebe_numero();
                        i = 1;
                    } 
                    cout << "Digite o segundo número: ";
                    b = recebe_numero();
                    if(b == 0){
                        cout << "!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                        cout << "Erro – Divisão por zero" << endl;
                        cout << "!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                        break;
                    }
                    cout << a << " / " << b << " = " << calculadora->Quocient(a, b) << endl << endl;
                    break;
                default:
                    cout << "Operação Inválida" << endl;
                    break;
            }
        }
        a = calculadora->getResultado();
    } while(operation != 's' || operation != 'S');
    delete calculadora;
    return 0;
}

float Calculadora::Add(float num1, float num2){
    N1 = num1 + num2;
    return N1;
}

float Calculadora::Subtract(float num1, float num2){
    N1 = num1 - num2;
    return N1;
}

float Calculadora::Product(float num1, float num2){
    N1 = num1 * num2;
    return N1;
}

float Calculadora::Quocient(float num1, float num2){
    N1 = num1 / num2;
    return N1;
}

float Calculadora::getResultado(){
    return N1;
}

void Calculadora::Reset(){
    N1 = 0;
}
