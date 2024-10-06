#pragma once

#include <string>
#include <iostream>

using namespace std;

class Car{
    private:
        double price;
        double power;
        double speed;
    public:
        Car();
        Car(double po, double pr);

        double getPrice();
        double getPower();
        double getSpeed();

        void setPrice(double p);
        void setPower(double p);
        void setSpeed(double s);

        void accelerate(int newSpeed);
        void accelerate(string maxmin);
        void accelerate(double timeacc, double acc);

        void showinfo();

};


Car::Car(){
    speed = 0;
}

Car::Car(double po, double pr){
    price = pr;
    power = po;

}

double Car::getPrice(){
    return price;
}

double Car::getPower(){
    return power;
}

double Car::getSpeed(){
    return speed;
}

void Car::setPrice(double p){
    price = p;
}

void Car::setPower(double p){
    power = p;
}

void Car::setSpeed(double s){
    speed = s;
}

void Car::accelerate(int speed){
    setSpeed(speed);
}

void Car::accelerate(string maxmin){
    if(maxmin == "max"){
        setSpeed(120);
    }
    if(maxmin == "min"){
        setSpeed(60);
    }
}

void Car::accelerate(double timeacc, double acc){
    speed = getSpeed() + acc * timeacc * 360/1000;
}

void Car::showinfo(){
    cout << getPower() << endl;
    cout << getPrice() << endl;
    cout << getSpeed() << endl;
}