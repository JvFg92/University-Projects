#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class PhoneNumber{
    friend std::ostream &operator<<( std::ostream &, const PhoneNumber & );
    friend std::istream &operator>>( std::istream &, PhoneNumber & );

    private:
    string areaCode;
    string exchange;
    string line;

};

ostream &operator<<(ostream & output, const PhoneNumber &number){
    output<<"("<<number.areaCode<<") "<<number.exchange<<"-"<<number.line;
    return output;
}

istream &operator>>(istream &input, PhoneNumber &number){
    input.ignore();
    input>>setw(3)>>number.areaCode;
    input.ignore(2);
    input>>setw(3)>>number.exchange;
    input.ignore();
    input>>setw(4)>>number.line;

    return input;
}

int main(void){
    PhoneNumber phone;
    cout<<"Enter the phone number in the form (123) 456-7890:"<<endl;
    cin>>phone;
    cout<<"The phone was:"<<phone<<endl;
   
   
    return 0;
}