#include <iostream>
#include <type_traits>
#include "Car.h"

using namespace std;

template <class T>
Car<T>::Car(){
    Power=1000;
    Price=500;
    cout<<"Default constructor"<<endl;
    number_of_cars ++;
}

template <class T>
Car<T>::Car(T Power2, T Price2){
    Power=Power2;
    Price=Price2;
    cout<<"Custom constructor"<<endl;
    number_of_cars ++;
}

int main(){
    Car<double> BMW(328,41245);
    BMW.showinfo();

    Car<char> Volvo(555,60000);
    Volvo.showinfo();

    return 0;
}