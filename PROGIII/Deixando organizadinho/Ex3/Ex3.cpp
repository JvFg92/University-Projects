#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


using namespace std;

template <class T>
class Stack{
    vector<T> elems;
    
    public:
        void push(T const&);
        void pop();
        T top() const;
        
        bool empty() const {
            return elems.empty();
        }
        void returncontent();
};

template <class T> 
void Stack<T>::push (T const& elem){
    elems.push_back(elem);
}

template <class T>
void Stack<T> :: pop(){
    if (elems.empty()){
        throw out_of_range("Stack<>::pop(): empty stack");

    }
    elems.pop_back();
}

template <class T>
void Stack<T>:: returncontent(){
    for (unsigned int i=0; i< elems.size(); i++)
        cout << elems[i] << endl;
}

int main(){
    Stack<int> intStack;
    Stack<string> stringStack;
    
    intStack.push(1);
    intStack.push(8);
    intStack.push(4);
    intStack.push(5);
    
    intStack.returncontent();
    cout << endl;
    
    stringStack.push("A");
    stringStack.push("B");
    stringStack.push("C");
    stringStack.push("D");
    
    stringStack.returncontent();
    
    return 0;
}