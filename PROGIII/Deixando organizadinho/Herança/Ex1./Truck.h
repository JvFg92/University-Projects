#include "Car.h"
#include <string>
#include <iostream>

using namespace std;


class Truck:public Car{
    public:
    Truck(double Power,double Price,string typefload, unsigned nofWheels);
    void loadTruck();
    void unloadTruck();
    void status();

    private:
    string typeofLoad;
    bool Loaded;
    unsigned numberofWheels;
};

Truck::Truck(double Power,double Price,string tofload, unsigned nofWheels):Car(Power,Price){
    typeofLoad=tofload;
    numberofWheels=nofWheels;
    Loaded=false;

}
void Truck::loadTruck(){
    Loaded=true;
}
void Truck::unloadTruck(){
    Loaded=false;
}
void Truck::status(){
std::cout<<"The truck is "<< (Loaded?"loaded": "not loaded") <<std::endl;
std::cout<<"The truck contains "<< typeofLoad << std::endl;
std::cout<< "The truck has "<< numberofWheels <<" wheels"<<std::endl;
std::cout<<"The truck has a motor of "<< getPower() <<"hp" << std::endl; 
std::cout<< "The truck costs "<< getPrice() <<std::endl;
}