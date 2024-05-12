//prime number
#include <iostream>
using namespace std;
void primeSeive(int n){
    for (int i =2; i<=n; i++){
        if(prime[i]==0){
            for(int j=i*i; j<=n; j+= i){
                prime[j] = 1;
            } 
        }
    }
    for(int i=2; i<=n; i++){
        if (prime[i] == 0){
            cout << i << " ";
        }
    }cout << endl;
}

//prime factorisation
#include <iostream>
using namespace std;
void primefactorisation(int n){
    int spf[n+1] = {0};
    for (int i = 2; i <=n; i++){
        spf[i] = i;
    }
    for (int i = 2; i <=n; i++){
        if (spf[i] == i){
            for (int j = i*i; j <= n; j+= i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
    while (n != 1){
        cout << spf[n] << " ";
        n=n/spf[n];
    }
}


//Inclusion-Exclusion Principle
//how many numbers between 1 ans 1000 are divisible by 5 or 7
#include <iostream>
using namespace std;
int divisible(int n, int a , int b){
    int c1=n/a;
    int c2=n/b;
    int c3=n/(a+b);
    return c1+c2-c3;
}
int main(){
    int n, a, b;
    cin>>n>>a>> b;
    cout << divisible(n,a,b)<<endl;
    return 0;
}


//Euclid algorithm to find GCD
#include <iostream>
using namespace std;
int gcd(int a, int b){
    while(b != 0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}