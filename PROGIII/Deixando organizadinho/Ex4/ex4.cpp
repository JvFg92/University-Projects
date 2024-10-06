#include <iostream>

using namespace std;

template<typename Some> void show(Some s){cout<<"Template Value: "<<s<<endl;}

void show(int s){cout<<"Integer Value: "<<s<<endl;}

int main(){
    show('E');
    show(42);
    show(42.42);
    return 0;
}