//Diophantine equations
/* these are the polynomial equations for which integral solution exists*/
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 1e5+2, MOD = 1e9+7;
struct triplet{
    int x,y,gcd;
    };
    
triplet extendedEuclid(int a, int b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }
    triplet smallAns = extendedEuclid(b,a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}
signed main(){
    int a, b;
    cin>>a>>b;
    triplet ans=extendedEuclid(a,b);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
    return 0;
}
//multiplication Modulo Inverse
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 1e5+2, MOD = 1e9+7;
struct triplet{
    int x,y,gcd;
};
triplet extendedEuclid(int a, int b)
{
    if(b==0){
        triplet ans;
        ans.x = 1;
        ans.gcd = a;
        ans.y=0;return ans;
    }
    triplet smallAns = extendedEuclid(b,a%b);
    triplet ans;
    ans.x = smallAns.y;
    ans.gcd = smallAns.gcd;
    ans.y=smallAns.x- (a/b)*smallAns.y;
    return ans;}
    int multiplicativeModuloInverse(int a, int m)
    {
        triplet temp = extendedEuclid(a,m);
        return temp.x;
    }
signed main(){
    int a,m;
    cin>>a>>m;
    cout<< multiplicativeModuloInverse(a,m)<<endl;
    return 0;
} 
    //Euler Totient function
    #include "bits/stdc++.h"
    using namespace std;
    #define int long long
    const int N = 1e5+2, MOD = 1e9+7;
    int totient[N];
    signed main(){
        for(int i=0;i<N;i++){
            totient[i] = i;
        }
        for(int i=2; i<N; i++){
            if(totient[i] == i){
                for(int j=2*i; j<N; j+=i){

                    totient[j] *= i-1;
                    totient[j] /= i;
                }
                totient[i] = i-1;
            }
        }
        for(int i=2; i<11; i++){
            cout<<totient[i]<<" ";
        }return 0;
    }
    //binary Exponentiation
    #include "bits/stdc++.h"
    using namespace std;
    #define int long long
    const int N = 1e5+2, MOD = 1e9+7;
    int power(int a, int n){
        a%=MOD;
        int ans = 1;
        while(n>0){
            if(n&1)
            ans = (ans*a)%MOD;
            a=a*a%MOD;
            n= n>>1;
        }return ans;
    }
    signed main(){
        int a,n;
        cin>>a>>n;
        cout<<power(a,n)<<endl;
    }
