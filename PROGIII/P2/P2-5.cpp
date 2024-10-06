#include <iostream>

using namespace std;

class A{
    public:
        A(){std::cout<<"4";}
        ~A(){std::cout<<"1";}
};

class B: public A{
    public:
        B(){std::cout<<"3";}
        ~B(){std::cout<<"2";}
};

class C: public B{
    public:
        C(){std::cout<<"2";}
        ~C(){std::cout<<"3";}
};

class D: public C{
    public:
        D(){std::cout<<"1";}
        ~D(){std::cout<<"4";}
};

int main(){
    A cA;
    B cB;
    C cC;
    {
    D cD;
    std::cout<<"\n";
    }
    std::cout<<"\n";

}