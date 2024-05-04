//check whether the given number is prime or not.
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool flag=0;
    for(int i=2;i<n;i++){
        if(n%i==0){
            cout<<"Non Prime"<<endl;
            flag=1;
            break;
        }
    }if(flag==0){ cout<<"Prime"<<endl;}
    return 0;
}


//print all the prime numbers between two given numbers using functions.
#include <iostream>
#include<math.h>
using namespace std;

   bool isPrime(int num){
       for(int i=2;i<sqrt(num);i++){
           if(num%i==0){
               return false;
           }
       }return true;
   }
   
int main(){
    int a,b;
    cin>>a>>b;
    
    for(int i=a;i<=b;i++){
        if(isPrime(i)){
            cout<<i<<endl;
        }
    }return 0;
}