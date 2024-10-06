#include "Car.h"
#include <string>
#include <iostream>
#include "Truck.h"
#include "PassengerCar.h"
using namespace std;



int main(){

    PassengerCar BMW(382,41245,4,0);
    BMW.status();
    BMW.loadPassenger(2);
    BMW.loadPassenger(3);
    BMW.status();
    BMW.unloadPassenger(1);
    BMW.unloadPassenger(2);
    BMW.status();


    Car Ferrari(710,350000);
    Truck Volvo(420,50000,"Soy",8);

    Volvo.status();


    return 0;
}