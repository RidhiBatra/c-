#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

int sum=0;
while (n>0){
    int lastdigit=n%10;
    sum+=pow(lastdigit,3);
    n=n/10;
    }
    if (sum==original){
        cout<<"Armstrong"<<endl;
    }
    else{
        cout<<" not Armstrong"<<endl;
    }return 0;}