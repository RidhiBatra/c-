//factorial of a number n using functions.(n! = n*n-1*n-2*n-3....*1)
#include <iostream>
using namespace std;
 int fact(int n){
     int factorial=1;
     for(int i=2; i<=n; i++){
         factorial*=i;
     }return factorial;
 }
 int main(){
     int n;
     cin>>n;
     int ans = fact(n);
     cout<<ans<<endl;
     return 0;
 }