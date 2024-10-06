#include <iostream>
using namespace std;

class Polygon{
    protected:
    int width, height;

    public:
    Polygon(int a, int b): width(a), height(b){}
    void set_values(int a , int b){  width=a; height=b; }
    virtual int area()=0;
    virtual ~Polygon(){cout<<"Polygon Destroyed"<<endl;}
};

class Rectangle: public Polygon{
    public:
    Rectangle(int a, int b):Polygon(a,b){}
    int area(){return width*height;}
    virtual ~Rectangle(){cout<<"Rectangle Destroyed"<<endl;}
};

class Triangle: public Polygon{
    public:
    Triangle(int a, int b):Polygon(a,b){}
    int area(){return width*height/2;}
    virtual ~Triangle(){cout<<"Triangle Destroyed"<<endl;}
};

int main(){

    Polygon * ppoly1= new Rectangle (4,5);
    Polygon * ppoly2= new Triangle (4,5);

    ppoly1->set_values(4,5);
    ppoly2->set_values(4,5);

    cout<< ppoly1->area()<<endl;
    cout<< ppoly2->area()<<endl;


    return 0;
}