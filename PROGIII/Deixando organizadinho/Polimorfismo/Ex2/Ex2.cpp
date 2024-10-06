#include <iostream>
using namespace std;

class base{
    public:
    virtual void show(){cout<< "In Base class"<<endl;}
};

class derived: public base{
    public:
    void show(){cout<< "In Derived class"<<endl;}
};

int main(){
    base * bp= new derived;

    bp->show();

    return 0;
}