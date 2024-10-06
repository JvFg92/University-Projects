template<class T = double>
class Car{
    public:
        Car();
        Car( T Power2, T Price2);

        Car<T> & operator = (const Car & obj);

        Car<T> (const char *Power2, const char *Price2);

        ~Car();

        T getPower();
        T getPrice();

        void showinfo() const;

        static unsigned int getNumCars();

        Car<T> &setPower(T pwr);
        Car<T> &setPrice(T pric);
    
    private:
        T Power;
        T Price;

        static unsigned int number_of_cars;

};

