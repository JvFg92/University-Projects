#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "car.h"
using namespace std;

int main(){
    Car BMW(328,41245);
    cout<<BMW.getPower()<<endl;
    cout<<BMW.getPrice()<<endl;
    return 0;
}