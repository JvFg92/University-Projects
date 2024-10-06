#ifndef ELECTRIC_BIKE_H_
#define ELECTRIC_BIKE_H_

#include <iostream>

class electricBike{
    public:
        electricBike();
        electricBike(double _motorWhats);
        ~electricBike();
        double getMotorWhats();
        void setMotorWhats(double _motorWhats);
    protected:
        double motorWhats;
};

electricBike::electricBike(){
    setMotorWhats(100);
}

electricBike::electricBike(double _motorWhats){
    setMotorWhats(_motorWhats);
}

electricBike::~electricBike(){}

double  electricBike::getMotorWhats(){return motorWhats;}
void  electricBike::setMotorWhats(double _motorWhats){motorWhats= _motorWhats;}



#endif