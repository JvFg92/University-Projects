#include <iostream>
using namespace std;

class A{
    public:
    A(){ cout<<"A\n"<<endl;}
    ~A(){cout<<"~A\n";}
};
class B: public A{
    public:
    B(){ cout<<"B\n"<<endl;}
    ~B(){cout<<"~B\n";}
};
class C: public B{
    public:
    C(){ cout<<"C\n"<<endl;}
    ~C(){cout<<"~C\n";}
};
class D: public C{
    public:
    D(){ cout<<"D\n"<<endl;}
    ~D(){cout<<"~D\n";}
};
int main(){
    cout<<"construindo A"<<endl;
    A cA;
    cout<<"construindo B"<<endl;
    B cB;
    cout<<"construindo C"<<endl;
    C cC;
    {
    cout<<"construindo D"<<endl;
    D cD;
    cout<<"Destruindo D"<<endl;
    }
    cout<<"feito"<<endl;
    
    return 0;
}