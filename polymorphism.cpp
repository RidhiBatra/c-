#include<iostream>
#include"bits/stdc++.h"
using namespace std;
//function overloading
class ApnaCollege{
    public:
    void fun(){
        cout << "I am a function with no arguments" <<endl;
    }
    void fun(int x)
    {
        cout << "I am a function with int argument" <<endl;
    }
    void fun(double x)
    {
        cout << "I am a funcion with double arguments" << endl;
    }
};
int32_t main(){
    ApnaCollege obj;
    obj.fun();
    obj.fun(4);
    obj.fun(6.2);
}

//operator overloading
#include<iostream>
#include"bits/stdc++.h"
using namespace std;
class complex{
    private:
    int real, imag;
    public:
    complex(int r,int i){
        real=r;
        imag = i;
    }
    complex operator + (complex const &obj){                   //& ka mtlb hota hai by reference liya hai.
        complex res;
        res.imag = imag + obj.imag;
        res.real = real + obj.real;
        return res;
    }
    void display(){
        cout<< real<<" +i"<<imag <<endl;
    }
};
int32_t main(){
    complex c1(12,7), c2(6,7);
    complex c3= c1 + c2;
    c3.display();
    return 0;
}

//runtime polymorphism
#include <iostream>
#include"bits/stdc++.h"
using namespace std:
class base{
    public:
    void print(){
        cout<<"this is the base class's print function "<<endl;

    }
    void display(){
        cout<< "this is the base class's display function"<<end l;
    }
};
class derived: public base{
     public:
    virtual void print(){
        cout<<"this is the derived class's print function "<<endl;

    }
    void display(){
        cout<< "this is the derived class's display function"<<end l;
    }
};
int32_t main(){
    base *baseptr;
    derived d;
    baseptr= &d;
    baseptr -> print();
    baseptr -> display();
    return 0;
}

}