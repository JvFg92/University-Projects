#pragma once
class Bike{
    public:
        Bike();
        Bike(double _gearspeed, double _wheelsize, double _price);
        Bike(const Bike & obj);
        ~Bike();
        double getGearspeed();
        void setGearspeed(double _gearspeed);
        double getWheelsize();
        void setWheelsize(double _wheelsize);
        double getPrice();
        void setPrice(double _price);
        virtual void discount();

    protected:
        double price;
        double gearspeed;
        double wheelsize;

};

Bike::Bike(){
    gearspeed=21;
    wheelsize=29;
    price=900;
}

Bike::Bike(double _gearspeed, double _wheelsize, double _price){
    gearspeed=_gearspeed;
    wheelsize=_wheelsize;
    price=_price;
}

Bike:: Bike(const Bike & obj){
    gearspeed=obj.gearspeed;
    wheelsize=obj.wheelsize;
    price=obj.price+100;
}

Bike::~Bike(){}

double Bike::getGearspeed(){return gearspeed;}
void Bike::setGearspeed(double _gearspeed){gearspeed= _gearspeed;}

double Bike::getWheelsize(){return wheelsize;}
void Bike::setWheelsize(double _wheelsize){wheelsize= _wheelsize;}

double Bike::getPrice(){return price;}
void Bike::setPrice(double _price){price= _price;}

void Bike::discount(){return setPrice(price*0.95);}