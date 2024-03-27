#include <iostream>
using namespace std;
int getBit(int n, int pos){              //getbit
    return (( n & (1<<pos))!=0);
}
int setBit(int n, int pos){
    return (n | (1<<pos));                 //setbit
}
int clearBit(int n, int pos){
    int mask = ~(1<<pos);               //clearBit
    return (n & mask); 
}
int updateBit (int n, int pos, int value){
    int mask = ~(1<<pos);             //updateBit
    n= n & mask;
    return (n | (value<<pos));
}
int main(){
    cout<<getBit(5,2)<<endl;
    cout<<setBit(5,1)<<endl;
    cout<<clearBit(5,3)<<endl;
    cout<<updateBit(6,2,1)<<endl;
return 0;}
