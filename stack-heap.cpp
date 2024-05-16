#include <iostream>
using namespace std;

//stack
int add (int num1,int num2){
    return num1+num2;
}
int main(){
    int a=2;
    int b=3;
    int sum = add(a,b)
    cout<<sum<<endl;
    return 0;
}

//heap
int main(){
    int a=10;   //stored in stack
    int*p = new int();  //allocate memory in heap
    *p = 10;
    delete(p);    //deallocate memory
    p=new int[4];
    delete[]p;
    p=NULL;
    return 0;
}