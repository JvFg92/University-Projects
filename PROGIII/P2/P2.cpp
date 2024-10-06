#include <iostream>

using namespace std;

//Classe Bike
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

//Classe Electric Bike:
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

//Classe KidsBike:
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

//1:
/*
kidsBike t2(){
    kidsBike object;
    return object;
}
int main(){

    Bike A3(23,26,1200);
    kidsBike AK3 = t2();

    cout<< AK3.getGearspeed()<<endl;
    cout<< AK3.getWheelsize()<<endl;
    cout<< AK3.getPrice()<<endl;
    cout<< AK3.getMotorWhats()<<endl;
    cout<<((AK3.getTrainingWheels())?"True":"False")<<endl;



    return 0;
}
*/

//2:
/*
void t(kidsBike object){
    object.setPrice(object.getPrice()+500);
    object.setWheelsize(object.getWheelsize()-3);
    object.setGearspeed(object.getGearspeed()+7);
    object.setMotorWhats(object.getMotorWhats()-100);
    object.setTrainingWheels(!object.getTrainingWheels());

    cout<<object.getGearspeed()<<endl;
    cout<<object.getWheelsize()<<endl;
    cout<<object.getPrice()<<endl;
    cout<<object.getMotorWhats()<<endl;

    cout<<((object.getTrainingWheels())?"True":"False")<<endl;
}

int main(){
    kidsBike AK2;
    t(AK2);
    return 0;
}*/

//3:
/*
kidsBike t2(){
    kidsBike object;
    object.setPrice(object.getPrice()+165);
    object.setWheelsize(object.getWheelsize()-8);
    object.setGearspeed(object.getGearspeed()/21);
    return object;
}

int main(){
    kidsBike AK3 = t2();
    Bike *BK = &AK3;
    cout<<AK3.getGearspeed()<<endl;
    cout<<AK3.getWheelsize()<<endl;
    BK->discount();
    cout<<AK3.getPrice()<<endl;
    cout<<AK3.getMotorWhats()<<endl;
    cout<<((AK3.getTrainingWheels())?"True":"False")<<endl;
    return 0;
}**/

//4:
/*
kidsBike t2(){
    kidsBike object;
    return object;
}

int main(){

    kidsBike AK5(1,12,200,150,false);
    kidsBike AK6 = t2();
    AK6 = AK6 + AK5 * AK6;
    cout<<AK6.getGearspeed()<<endl;
    cout<<AK6.getWheelsize()<<endl;
    cout<<AK6.getPrice()<<endl;
    cout<<AK6.getMotorWhats()<<endl;
    cout<<((AK6.getTrainingWheels())?"True":"False")<<endl;

    return 0;
}*/