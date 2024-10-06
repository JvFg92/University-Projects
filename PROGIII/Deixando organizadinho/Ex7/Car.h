#pragma once

template <class T = double >
class Car{

    //static_assert(is_floating_point<T>::value, "tipos suportados: float e double");

    public:
        Car();
        Car(T Power2, T price2);
        Car(const Car & obj);
        Car<T> & operator = (const Car & obj);
        Car<T> (const char *Power2, const char *price2);
        ~Car();

        T getPower ();
        T getPrice ();
        void showinfo() const;

        static unsigned int getNumCars();

        Car<T> &setPower (T pwr);
        Car<T> &setPrice (T pric);

    private:
        T Power;
        T price;
        static unsigned int number_of_cars;
};

template <class T>
Car<T>::Car(){
    Power=100;
    price=10000;
    number_of_cars++;
    cout<<"default constructor"<<endl;
}


template <class T>
Car<T>::Car(T Power2, T price2){
    if (is_floating_point<T>::value){
        Power=Power2;
        price=price2;
        number_of_cars++;
        cout<<"custom constructor"<<endl;
    }
}


template <class T>
Car<T>::Car (const Car & obj){
    Power=obj.Power;
    price=obj.Price;
    number_of_cars++;
    cout<<"default copy constructor"<<endl;
}


template <class T>
Car<T>::~Car(){
    cout<<"custom destructor"<<endl;
}


template <class T>
T Car<T>::getPower(){
    return Power;
}


template <class T>
T Car<T>::getPrice(){
    return price;
}


template <class T>
Car<T>& Car<T>::setPower (T Power){
    this->Power = Power;
}


template <class T>
Car<T>& Car<T>::setPrice (T price){
    this->price = price;
}

template <class T> 
unsigned int Car<T>::number_of_cars = 0;


template <class T>
unsigned int Car<T>::getNumCars(){
    return number_of_cars;
}


template <class T>
Car<T> & Car<T>::operator=(const Car & obj){
    Power=obj.Power+1;
    price=obj.price+1;
    std::cout<<"assignment operator"<<endl;
    return *this;
}


template <class T>
void Car<T>::showinfo() const{
    if (is_floating_point<T>::value){
        cout<<"Power: "<<Power<<endl;
        cout<<"Price: "<<price<<endl; 
        number_of_cars++;
    }
    else{
        cout<<"Tipo invalido de variavel"<<endl;
    }
}