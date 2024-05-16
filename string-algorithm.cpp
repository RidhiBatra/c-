//find number of unique strings
#include "bits/stdc++.h"
using namespace std;
int main(){
    vector<string> strings = {"aa","ab","aa","b","cc","aa"};
    sort(strings.begin(),strings.end());
    int distinct = 0;
    for(int i=0; i<strings.size(); i++){
        if(i==0 or strings[i] != strings[i-1]){
            distinction++;
        }
    }cout<<distinct<<"\n";
}
//calculate the indices of the occuremces of string s in it
#include <bits/stdc++.h>
using namespace std;
vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n,0);
    for(int i = 1;i<n;i++){
        int j = pi[i-1];
        while(j>0 and s[i]!=s[j])
        j= pi[j-1];
        if(s[i] == s[j])
        j++;
        pi[i] = j;
    }
    return pi;
    
}
int main(){
    string s = "na";
    vector<int> prefix= prefix_function(s);
    string t = "apna college";
  int pos = -1;
  int i(0),j(0);
  while(i<t.size()){
    if(t[i] == s[j]){
        j++; i++;
    }
    else{
        if(j!=0)
        j= prefix[j-1];
        else
        i++;
    }
    if(j==s.size()){
        pos = i-s.size();
        break;
    }
  }cout<<pos;
}
//Rabin-Karp Algorithm
//calculate the indices of the occurance of string s in it
#include "bits/stdc++.h"
using namespace std;
int p = 31;
const int N = 1e5+7, m = 1e9+7;
vector<long long> powers(N);
int main(){
    string s = "na";
    string t = "apnacollege";
    int T = t.size(),S= s.size();
    vector<long long> h(T+1, 0);
    for(int i =0; i<T;i++){
        h[i+1] = (h[i] + (t[i] - 'a' + 1)*power[i])%m;
    }
    vector<long long> h(T+1,0);
    for(int i=0;i<S;i++){
        h_s = (h_s + (s[i] - 'a' + 1)*power[i])%m;
    }
    for(int i =0;i+S -1<T; i++){
        long long cur_h = (h[i+S] - h[i] + m)%m;
        if(cur_h == (h_s * power[i]) %m){
            cout<<"Found at index" <<i<<"\n";
        }
    }
}