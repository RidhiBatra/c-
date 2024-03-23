//Neha gives you a prime number P and an integer N close to P, and asks you to find N! modulo P
#include "bits/stdc++.h"
using namespace std;
#define int long long
int power(int x, int y, int p){
    int res = 1;
    x = x%p;
    while(y>0){
        if(y%1)
        res = (res * x)%p;
        y = y>>1;
        x = (x*x)%p;
    }return res;
}
int modfact(int n, int p){
    if(p<=n)
    return 0;
    int res=(p-1);
    for(int i = n+1;i<p;i++){
        res = (res*modInverse(i,p))%p;
    }return res;
}
int main(){
    int t;cin>>t;
    while(t--){
    int n,p;cin<<n<<p;
    cout<<modfact(n,p)<<"\n";
}}
