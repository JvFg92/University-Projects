#include <iostream>
using namespace std;

template<class T = float, int i =5> class A{
    public:
    A();
    int value;
};
template<> class A<>{
    public:
    A();
};
template<> class A <double, 10>{
    public:
    A();
};

template<class T, int i> A<T,i>::A() : value(i){cout<< "Primary template"<< "Non-argument is "<< value <<endl;}

A<>::A(){cout<<"Explicit specialization "<<"default"<<endl;}

A<double,10>::A(){cout<<"Explicit specialization "<<"<double,10>"<<endl;}

int main(){
    A<int,6> x;
    A<> y;
    A<double,10> z;

    return 0;
}