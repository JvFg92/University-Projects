#pragma once

class Car{
    private:
        double Power;
        double Price;

    public:
        // Car();
        Car(double _Power, double _Price);
        double getPower();
        double getPrice();

};

Car & Car::operator=(const Car & obj){
    Power=obj.Power+1;
    Price=obj.Price+1;
    return *this;
}
Car::Car(double _Power, double _Price){
    Power= _Power;
    Price= _Price;
}

double Car::getPower(){
    return Power;
}
double Car::getPrice(){
    return Price;
}