#include <iostream>
#include <vector>

using namespace std;

class Animal{
    public:
        virtual void move(){cout<<"Anda"<<endl;}
};
class Fish:public Animal{
    public:
    void move(){cout<<"Nada"<<endl;}
};
class Frog: public Animal{
    public:
    void move(){cout<<"Pula"<<endl;}
}; 

class Bird: public Animal{
    public:
    void move(){cout<<"Voa"<<endl;}
}; 



int main(){
    Fish Nemo;
    Frog Kermit;
    Bird Blu;

    vector<Animal*> animals;
    animals.push_back(&Nemo);
    animals.push_back(&Kermit);
    animals.push_back(&Blu);

    for (Animal * a_list:animals)a_list->move();



    return 0;
}