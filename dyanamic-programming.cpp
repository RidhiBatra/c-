//fibonacci series
#include <iostream>
using namespace std;
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
const int N = 1e3+2, MOD = 1e9+7;
int fib(int n)
{
    if(n==0)
    return 0;
    if (n==1)
    return 0;
    if(n==2)
    return 1;
    if(dp[n] != -1)
    return dp[n];
dp[n] = fib(n-2) +fib(n-1);
 return dp[n];
}
signed main(){
int n;
cin>> n;
rep(i,0,N)
{
    dp[i] = -1;
}
cout << fib(n) << endl;
return 0;
}
//Minimum number of squares whose sum equals to given number 'n'
const int N = 1e3+2, MOD = 1e9+7;
int MinSquare(int n)
{
    if(n==1 || n==2 || n==3||n==0)
    return n;
    int ans = MOD;
    for(int i=1; i*i <= n; i++){
        ans = min(ans, 1+MinSquare(n-i*i));
    }
    return ans;
}
signed main(){
    int n;
    cin >> n;
    cout << MinSquare(n)<<endl;
    return 0;
}
//coin change problem
//given a set of coins and a value V. find the umber of ways in which we can make change of v
//code (memorization)
int fun(vi &a, int n, int x){
    if(x == 0)
    return 1;
    if(x<0)
    return 0;
    if( n <= 0 && x > 0)
    return 0;
    if(dp[n][x] != -1)
    return dp[n][x];
    dp[n][x] fun(a,n-1,x) + fun(a,n,x-a[n-1]);
    return dp[n][x];
}
void solve(){
    int n;
    cin>>n;
    rep(i,0,N){
    dp[i][j] = -1;
} vi a(n);
rep(i,0,n)
cin >> x;
cout << fun(a,n,x) << endl;}
//code (iterative)
void solve(){
    int m;
    cin>>m;
    vi s(m);
    rep(i,0,m)
    cin>>s[i];
    int x;
    cin>>x;
    vvi dp(m+1, vector<int>(x+1,0));
    dp[0][0] =1;
    rep(i,1,m+1){
        rep(j,0,x+1){
            if(j-s[i-1]>=0)
            dp[i][j] += dp[i][j-s[i-1]];
            dp[i][j] += dp[i-1][j];
        }
    }cout <<dp[m][x]<<endl;
}
//code (space optimization)
void solve(){
    int m;
    cin>>m;
    vi s(m);
    rep(i,0,m)
    cin>>s[i];
    int x;
    cin>>x;
    vi dp(x+1,0);
    dp[0] = 1;
    rep(i,0,m){
        rep(j,0,x+1){
            if(j-s[i] >= 0)
            dp[j] += dp[j-s[1]];
        }
    }
    cout<<dp[x] <<endl;
}
//0-1 Knapsack
//given an array of items with (weight, value) and a knapsack(bori) with weight w. find the maximum value of items that can be stolen and put
 //into a knapsack. we have to either pick full item or no item, we cannot take partial items
 int val[N] , wt[N];
 int dp[N][N];
 int Knapsack(int n, int w){
    if(w <= 0)
    return 0;
    if(n<=0)
    return 0;
    if(dp[n][w] != -1)
    return dp[n][w];
    if(w < wt[n-1]) dp[n][w] = Knapsack(n-1,w);
    else dp[n][w] = max(Knapsack(n-1,w) , Knapsack(n-1, w-wt[n-1]) + val[n-1]);
    return dp[n][w];
 }
 void solve(){              //code(iterative)
    rep(i,0,N){
        rep(j,0,N) dp[i][j] = -1;
    }
    int n; cin>>n;
    rep(i,0,n) cin>>wt[i];
    rep(i,0,n) cin>>val[i];
    int w; cin>>w;
    vvi dp(n+1, vi(w+1,0));
    rep(i,1,n+1){
        rep(j,0,w+1){
            dp[i][j] = dp[i-1][j];
            if(j-wt[i-1]>=0)
            dp[i][j] = max(dp[i][j], dp[i-1][j-wt[i-1]] + val[i-1]);
        }
    }
    cout << dp[n][w] <<endl;
    cout <<knapsack(n,w) << endl;
 }
 //longest Bitonic Subsequence
 //given an array a[] of size n, our task is to find the longest bitonic subsequence
 //bitonic: unlike LIS it can first increase and then decrease
 #include "bits/stdc++.h"
 using namespace std;
 int main(){
    int n= 8;
    vector<int> a= {1,11,2,10,4,5,2,1};
    vector<int> forward(n,1), backward(n,1);
    for(int i=0; i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i] > a[j])
            forward[i] = max(forward[i],1 + forward[j]); 
        }
    }
    for(int i= n-1; i>0; i--){
        for(int j=n-1;j<i;j--){
            if(a[i] > a[j]){
                backward[i] = max(backward[i], 1+backward[j]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,forward[i] + backward[i] - 1);
    }cout<<ans;
 }
 //longest increasing subsequence
 //problem: you are given an array[] of size n. find the length of longest increasing subsequences
 void solve(){
    int n;
    cin>>n;
    rep(i,0,n)
    dp[i] = -1;
    vi a(n);
    rep(i,0,n)
    cin>>a[i];
    vi dp(n,1);
    int ans = 0;
    rep(i,1,n){
        rep(j,0,i){
            if(a[j] < a[i])
            {
                dp[i] = max(dp[i] , 1+ dp[j]);
            }
            ans = max(ans.dp[i]);
        }
    }
    cout << ans << endl;
    cout << lis(a,n-1)<<endl;
 }
 int dp[N];
 int lis(vi &a, int n)
 {
    if(dp[n] != -1)
    return dp[n];
    dp[n] = 1;
    rep(i,0,n){
        if(a[n] > a[i])
        dp[n] = max(dp[n], l+lis(a,i));
    }
    return dp[n];                             
 }
 //matrix chain multiplication
 //problem: we are given n matrix, we have to multiply them in a way that the total number of operations are minimum
 int dp[N][N];
 void solve(){
    rep(i,0,N){
        rep(j,0,N)
        dp[i][j] = MOD;
    }
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n)
    cin>>a[i]; cout << fun(a,1,n-1)<<endl;
 }
 for(int gap=0; gap <= n-2; gap++){
    for(int i=1; i<=n-gap-1; i++)
    {
        int j = i+gap;
        if(i==j)
        dp[i][j] = 0;
        else if(j-i == 1)
        dp[i][j] = a[i-1]*a[i]*a[j];
        else{
            for(int k=i;k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] )
            }
        }
    }cout <<dp[1][n-1]<<endl;
 }
 int fun(vi &a, int i, int j)
 {
    if(j-1 == 1){
        dp[i][j] = a[i-1]*a[i]*a[j];
        return dp[i][j];
    }
    if(j==i)
    return 0;
    if(dp[i][j] != MOD)
    return dp[i][j];
    for(int k=i; k<j; k++){
        int temp = fun(a,i,k) + fun(a,k+1,j) + a[i-1]*a[k]*a[j];
        dp[i][j] = min(temp, dp[i][j]);
    }
    return dp[i][j];
 }
 //Minimum square sum
 //problem: given a number n, your task is to find the minimum number of numbers which sum to n
 int dp[N];
 int MinSquare(int n)
 {
    if(n==1|| n==2 || n==3 || n==0)
    return n;
    if(dp[n] != MOD)
    return dp[n];
    for(int i=1; i*i <= n; i++){
        dp[n] = min(dp[n],1 + MnSquare(n-i*i));
    }return dp[n];
 }
 void solve(){
    rep(i,0,N)
    dp[i] = MOD;
    int n;
    cin>>n;
    cout<< MinSquare(n)<<endl;
 }
 void(solve){
    int n;cin>>n;
    vi dp(n+1, MOD);
    dp[0]= 0;
    dp[1] = 1;
    dp[2] =2;
    dp[3] =3;
    for(int i=1; i*i <= n; i++)
    {
        for(int j=0; i*i+j <= n; j++)
        {
            dp[i*i +j] = min(dp[i*i+j], 1+dp[j]);
        }
    }cout<<dp[n] <<endl;

 }
 //optimal game strategy
 /* problem: rahul and neha are playing a coin game. they are given n coins with values x1,x2...xn where 'n' is always even. 
 they take alternate terms. in each turn, a player picks either the first coin or the last coin from the row and removes it from the row the va
 value of coin is recieved by that player.
 determine the maximum value that rahul can win if he moves first. Both the players play optimally*/
 #include "bits/stdc++.h"
 using namespace std;
 vector<int> a;
 int dp[100][100];
 int solve(int i, intj){
    if(i==j){
        return a[i];
    }
    if(i>j){
        return 0;
    }
    int l = a[i] + min(solve(i+2,j), solve(i+1,j-1));
    //A[i...j], rem coins = a[i+1...j]
    int r= a[j] + min(solve(i,j-2), solve(i+1,j-1));
    //A[i..j], rem coins = A[i...j-1]
    return dp[i][j] = max(1,r);
 }
 int main(){
    memset(dp,-1,sizeof(dp));
    int n; cin>>n;
    a= vector<int>(n);
    for(auto &i : a)
    cin>>i;
    cout<<solve(0,n-1);
 }
 // number of subsequences
 /* you are given a string s consisting of lower case latin letters ('a'-'z') and some '?'.
 your task is to find no. of subsequences 'abc' in all the strings '?' should be replaced by eitheer of {'a','b','c'}.
 
 optimal merge pattern: declare 4 variables
 (i) e --> denoting count of all possible strings upto current elements
 (ii) a --> denoting count of subsequences ('a') in all the strings upto current element
 (iii)  ab --> denoting count of subsequence('ab') in all the strings upto current element
 (iv)  abc --> denoting count of all subsequence ('a b c') in all the strings upto current element*/
 signed main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int e=1, a=0, ab=0, abc=0;
    rep(i,0,n){
        if(s[i] == 'a')
        a += e;
        else if(s[i] == 'b')
        ab += a;
        else if(s[i] == 'c')
        abc += ab;
        else if(s[i] == '?')
        {
            abc = 3*abc +ab;
            ab = 3*ab + a;
            a= 3*a + e;
        }

    }cout << abc <<endl;
 }
 //count the no. of binary string without consecutive 1s.
 //given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1's.
 /* states of the dp? 
 only depends on the last character and 'n' the states will be number of strings of length 'i' ending with 1 or 0 */
 int n; cin>>n;
 vector<int> fib(n+2,0);
 fib[0] = 1;
 fib[1] = 1;
 for(int i=2; i<n+1; i++){
    fib[i] = fib[i-1] + fib[i-2];
 }cout<< fib[n+1];
 //O-N knapsack
 /* given an array of items with their weight and value. find the maximum value of items that can be stolen using a knapsack
 of capacity W. you can choose infinite items of each type.*/
 #include "bits/stdc++.h"
 using namespace std;
 int main(){
    int n= 5, W = 11;
    vector<int> val = {3,2,4,5,1};
    vector<int> wt = {4,3,5,6,1};
    vector<int> dp(W+1,0);
    for(int j= 0;j<W; j++){
        for(int i=0; i<n; i++){
            if(j - wt[i] >= 0)
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }cout<<dp[W];
 }
 //maximun subarray sum (Kadane's algorithm)
 //you are given an array. tour task is to find the maximum sum of subarray which can be found using the above array
 const int N = 1e5+2;
 signed main(){
    int n;
    cin>>n;
    vi a(n); rep(i,0,n)
    cin>>a[i];
    int curr = 0, maxTillNow = 0;
    rep(i,0,n){
        curr += a[i];
        maxTillNow = max(curr, maxTillNow);
        if(curr<0)
        curr =0 ;
    }cout<<maxTillNow<<endl;
 }
 //freinds pairing problem
 /* given n freinds, each one ca remain single or can be paired up with some other freinds. each freind can be 
 paired only once. Find out the total number of ways in which freinds can remain single or can be paired up.*/

 /*Idea: let f(n) = ways n people can remain single or pair up
 for n-th person there are two choieces:
 1. n-th person remains single, we recur for f(n-1)
 2. n-th person pairs up with any of the remaining n-1 persons we get (n-1)*f(n-2)
 f(n) = f(n-1) + (n-1)*f(n-2)*/
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0] =1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + (i-1)*dp[i-2];
    }
    cout<<dp[n];
}
//ugly numbers
/*problems: ugly numbers are numbers whose prime factors are 2,3 or 5.
the first 10 ugly numbers are 1,2,3,4,5,6,8,9,10,12. by convention, 1 is included
given a number n, print the nth ugly number*/
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n= 10;
    int c2(0), c3(0), c5(0);
    vector<int> dp(n+1);
    dp[0] = 1;
    for(in i =1;i<n;i++){
        dp[i] = min({2*dp[c2], 3*dp[c3], 5*dp[c5]});
        if(2*dp[c2] == dp[i])
        c2++;
         if(3*dp[c2] == dp[i])
        c3++;
         if(5*dp[c2] == dp[i])
        c5++;
    }cout<<dp[n-1];
}
//LCS in 3 strings
#include "bits/stdc++.h"
using namespace std;
int dp[205][205][205];
int LCS(string &s1, string &s2, string &s3, int i, int j, int k){
   if(i == 0 or j==0 or k==0)
   return 0;
    if(s1[i-1] == s2[j-1] and s2[j-1] == s3[k-1]){
        return dp[i][j][k] =  1+ LCS(s1,s2,s3,i-1,j-1,k-1);
    }
    int l = LCS(s1,s2,s3,i-1,j,k);
    int r = LCS(s1,s2,s3,i,j-1,k);
    int p = LCS(s1,s2,s3,i,j,k-1);
    return max({l,r,p});
}
int main(){
    memset(dp, -1, sizeof(dp));
    string s1;cin>>s1;
    string s2; cin>>s2;
    string s3; cin>>s3;
    cout <<LCS(s1,s2,s3,s1.size(), s2.size(), s3.size());
    return 0;
}
//K ordered LCS
/* problem: print the LCS of two sequences given that you are allowed to chamge atmost k elements in the first sequence to any value you wish to*/
#include "bits/stdc++.h"
using namespace std;
int n,m,k;
vector<int> a,b;
int dp[2005][2005][7];
int solve(int i, int j, int k){
    if(i==n or j==m){
    return 0;}
    if(dp[i][j][k] != -1)
    return dp[i][j][k];
    int c1(0),c2(0), c3(0);
    if(a[i] == b[j])
    c1 = 1+solve(i+1,j+1,k);
    if(k>0)
    c2 = 1+ solve(i+1,j+1,k-1);
    c3 = max(solve(i+1,j,k), solve(i,j+1,k));return dp[i][j][k] =  max({c1,c2,c3});
}
int main(){
    cin>>n>>m>>k;
    a=vector<int>(n);
    b= vector<int>(m);
    for (auto &i : a)
    cin>>i;
    for (auto &i : b)
    cin>>i;
    cout<<solve(0,0,k);
}