#include "Car.h"
#include <string>
#include <iostream>

using namespace std;

class PassengerCar:public Car{
    public:
        PassengerCar(double Power,double Price,  int MaxPassenger,  int Passenger);
        void loadPassenger( int Passenger);
        void unloadPassenger( int Passenger);
        void status();
    private:
         int MaxPassenger;
         int Passenger;
        bool Loaded;
        

};

PassengerCar::PassengerCar(double Power,double Price,  int x,  int y){
    MaxPassenger=x;
    Passenger=y;
    Loaded=false;

}
void PassengerCar::loadPassenger( int passajeiro){
    if (Passenger<MaxPassenger)Passenger+=passajeiro;
    
    
    Loaded=true;
}
void PassengerCar::unloadPassenger( int passajeiro){
    Passenger-=passajeiro;
    Loaded=false;
}

void PassengerCar::status(){

 
    std::cout<<"The Car contains "<< Passenger << std::endl;
    std::cout<< "The Car has "<< ( MaxPassenger-Passenger) <<" remain passengers"<<std::endl;
    std::cout<<"The Car has a motor of "<< getPower() <<"hp" << std::endl; 
    std::cout<< "The Car costs "<< getPrice() <<std::endl;
}