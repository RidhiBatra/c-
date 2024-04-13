//greedy algorithm
//at present, jo best lage voh le lo.
/* -generally, sorting is done first while applying greedy algorithm
 - sometimes we do not realize that we are applying greedy because it comes from inside.
 -practise id the main key to get familiar with greedy techniques
 */
/*problem- you are given an array of Denominations and a value X. you need to find the minimum number of coins reqd to make value pf X.

Approach:- 1.start from the largest value, till we can include it, take it
2.else move on the smallest value
*/
signed main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n)
    cin>>a[i];
    int x;
    cin>>a[i];
    int x;
    cin>>x;
    sor(a.begin(), a.end, greater<int>());
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans += x/a[i];
        x -= x/a[i] * a[i];
    }
    cout <<ans<<endl;
    return 0;
}
//activity selection problem
/*problem: you are given n activities with their start and finish time. select the maximum number of activities that can be performed
by a single person, assuming that a person can only work on a single activity at a time*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        int start, end;
        cin>>start>>end;
        v.push_back({start,end});
    }
    sort(v.begin(), v.end(), [&](vector<int> &a,vector<int> &b){
        return [1] < b[1];
    });
    int take=1;
    int end = v[0][1];
    for(int i =1;i<n;i++){
        if(v[i][0] >= end){
            take++;
            end = v[i][1];
        }
    }cout<<take<<"\n";
    return 0;
}
//fractional knapsack
/*problem- we are given 'n' items with {wight, value} of each item and the capacity of knapsack(sack)'W'. we need to put these items in knapsack
such that final value of items in knapsack is maximum*/
bool compare(pii p1, pii p2){
    double v1 = (double) p1.ff/p1.ss;
    double v2 = (double) p2.ff/p2.ss;
    return v1>v2;
}

signed main(){
    int n;
    cin>>n;
    vii a(n);
    rep(i,0,n)
    {
        cin>>a[i].ff >> a[i].ss;
    }
    sort(a.begin(), a.end(), compare);
    int ans=0;
    rep(i,0,n){
        if(w >= a[i].ss){
            ans += a[i].ff;
            w -= a[i].ss;
            continue;
        }
        double vw =(double) a[i].ff/a[i].ss;
        ans += vw * w;
        w = 0;
        break;
    }
    cout <<ans <<endl;
    return 0;
}
//optimal merge pattern
/*problem- you are given n files with their computation times in an array
approach- choose/take any two files add their computation times and append it to the list of computation times.(cost = sum of compuattion times)
do this until we are left with only one file in the array. we have to do this operation such that
we get minimum cost finally.
1. push all elemments to a miniheap
2. take top 2 elements one by one and add the cost to the answer.push the merged file to the miniheap
3. when single element remains, output the cost */
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i=0; i<n; i++){
        minheap.push(a[i]);
    }
    int ans = 0; 
    while(minheap.size()> 1){
        int e1= minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();
        ans+= e1+e2;
        minheap.push(e1+e2);
    }
    cout << ans << endl;
    return 0;
}
//expedi(expidition)
/* /a group of cows grabbed a truck and ventured on an expidtion deep into the jungle. the truck leaks one unit of feul every
unit of distance it travels
to repair the truck the cows need to drive to nearest town(no more than 1000000 units distance). on this road, between the town and the
current location there are N(1<=N<=100000) fuels stop where the cow can stop to acquire additional fuel(1...100 units at each stop).
the cows want to make the minimum possible number of stops for fuels on the way to town.
capacity of the tank is sufficiently large to hold any amount of fuel.
Initial unit of fuel: p(1<=P<=1000000)
Initial distance from town: L
determine the minimum number of stops to reach the town */

/*Brute force: generate all subsequences of stops
2. iterate over all subsequences choose the one that is feasible and has minimum no. of stops.

optimal solution: 1. create a maxheap, which stores the fuels available at the stops that we have traversed
                2. sort the stops on the basis of distance of stops from initial position of truck
                3. keep iterating on the stops and whenever fuel in the tank of truck becomes empty take the
                fuel from the maxheap and add it to the truck(greedy step)
                4. maintain the count of stops from which we have taken fuel */
#include "bits/stdc++.h"
using namespace std;
int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int, int>>a(n);
        for(int i=0; i<n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        int l,p;
        cin >> l>>p;
        for (int i=0; i<n; i++)
        {
            a[i].first = l - a[i].first;
        }
        sort(a,begin(), a.end());
        int ans=0;
        int curr =p;
        priority_queue<int, vector<int>> pq;
        bool flag = 0;
        for(int i=0; i<n; i++)
        {
            if(curr >= l)
            break;
            while(curr<a[i].first){
                if(pq.empty())
                {
                    flag=1;
                    break;
                }
                ans++;
                curr += pq.top();
                pq.pop();
            }
            if(flag)
            break;
        }if(flag)
        break;
        pq.push(a[i].second);
    }if(flag){
        cout<< " -1 " <<endl;
        continue;
    }
    while(!pq.empty() && curr<l)
    {
        curr += pq.top();
        pq.pop();
        ans++;
           }
    if(curr < l){
        cout << " -1"<<endl;
        continue;
    }cout<< ans <<endl;
    return 0;       
}            
//Max and Min array difference
/*problem: you are given an array A, of n elements. you have to remove exactly n/2 elements from array A andadd it to another array B
find the maximum and minimum values of diffences between two arrays.
idea: To maximise abs(A[i] - A[j])
1. A[i] should be as large as psbl
2. a[j] should be as small as psbl*/
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i: a)
    cin>>i;
    sort(a.begin(), a.end());
    long long mn=0,mx = 0;
    for(int i= 0;i<n/2;i++){
        mx+= (a[i+n/2] - a[i]);
        mn += (a[2*i+1] - a[2*i]);
    }
    cout<<mn<<" "<<mx;
    return 0;
}    