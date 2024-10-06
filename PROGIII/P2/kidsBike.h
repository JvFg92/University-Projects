#ifndef KIDSBIKE_H_
#define KIDSBIKE_H_
#include "bike.h"
#include "electricBike.h"

#include <iostream>


class kidsBike: public Bike, public electricBike{
    public:
        kidsBike();
        kidsBike(double _gearspeed, double _wheelsize, double _price, double _motorWhats, bool _trainingWheels);
        ~kidsBike();
        bool getTrainingWheels();
        void setTrainingWheels(bool _trainingWheels);
        void discount();
        kidsBike &operator+ (const kidsBike &obj);
        kidsBike &operator* (const kidsBike &obj);
    private:
        bool trainingWheels;
};



kidsBike::kidsBike(){setTrainingWheels(true);}
kidsBike::kidsBike(double _gearspeed, double _wheelsize, double _price, double _motorWhats, bool _trainingWheels):Bike(_gearspeed, _wheelsize, _price), electricBike(_motorWhats){setTrainingWheels(_trainingWheels);}
kidsBike::~kidsBike(){}

bool kidsBike::getTrainingWheels(){return trainingWheels;}
void kidsBike::setTrainingWheels(bool _trainingWheels){trainingWheels=_trainingWheels;}

void kidsBike::discount(){return setPrice(price*0.85);}

kidsBike & kidsBike::operator+(const kidsBike &obj){
    gearspeed = gearspeed + obj.gearspeed;
    wheelsize = wheelsize + obj.wheelsize;
    price = price + obj.price;
    motorWhats = motorWhats + obj.motorWhats;
    trainingWheels = trainingWheels + obj.trainingWheels;
    return *this;
}

kidsBike & kidsBike::operator*(const kidsBike &obj){
    gearspeed = gearspeed * obj.gearspeed;
    wheelsize = wheelsize * obj.wheelsize;
    price = price * obj.price;
    motorWhats = motorWhats * obj.motorWhats;
    trainingWheels = trainingWheels * obj.trainingWheels;
    return *this;
}

#endif