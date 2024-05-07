//rain water harvesting
/* given non negative integers representing an elevation map where the width of each bar is 1
compute how much water it can trap after raining*/
#include<iostream>
#include "bits/stdc++.h"
using namespace std;

int rain_water(vector<int> a){
    stack<int> st;
    int n = a.size();
    for(int i =0; i<n; i++){
        while(!st.empty( ) and a[st.top()] < a[i]){
            int cur = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff = i - st.top() -1;
            ans += (min(a[st.top()], a[i]) - a[cur]) * diff;
        }
        st.push(i);
    }
    return ans;
}
int32_t main(){
    vector<int> a = {0,1,0,2,0,1,2,3,1,2,3,1};
    cout<<rain_water(a);
}

//redundant parentheses
/*given a valid mathematical expression, find whether it have redundant paranthesis or not. it 
contain the following operators +,-,*,/ */
#include<iostream>
using namespace<std>
int32_t main(){
    string s; cin>>s;
    for(int i =0; i<s.size(); i++){
        if(s[i] == '+' or s[i]== '-' or s[i] == '*' or s[i] == '/' ){
            st.push(s[i]);
        }
        else if(s[i] == '('){
            st.push(s[i]);

        }
        else if(s[i] == ')'){
            while(st.top()== '+' or st.top() == '-' or s[i] == '*' or s[i] == '/')
            {st.pop();}
        
        st.pop();
        }}cout<<ans;
}
 
//stock span problem
/* the span of the stock price today is defined as the maximum number of consecutive days(starting
from today and going backwards) for which the price of the stocks was less than or equal to
todays price. find the span of the stocks for all the days */
#include<iostream>
#include"bits/stdc++.h"
using namespace std;
vector<int> stockspan(vector<int> prices){
    vector<int> ans;
    stack<pair<int,int>> s;
    for(auto price: prices){
        int days =1;
        while(!s.empty() and s.top() <=price){
            days += s.top().second;
            s.pop();
        }
        s.push({price,days});
        ans.push_back(days);
    }
    return ans;
}
int32_t main(){
    vector<int> a ={100,80,60,70,60,75,85};
    vector<int> res = stockspan(a);
    for(auto i:res)
    cout<<i<<" ";
    cout<<"\n";
}

//3 sum
/*given an array and a value, find if there exists 3 numbers whose sum is equal to the given value'
'two point technique
1. sort the array
2. transverse the array and fix the first element of the triplet. the problrm reduces to find if there exists two elements
having sum equal to x-array[i]*/
#include<iostream>
#include "bits/stdc++.h"
using namespace std;
int32_t main(){
    int n; cin>>n;
    int target; cin>> target;
    vector<int> a(n);
    for( auto &i: a)
    cin>>i;
    bool found = false;
    sort(a.begin(), a.end());
    for(int i =0; i<n; i++){
        int lo = i+ 1, hi = n-1;
        while(lo<hi){
            int current = a[i] + a[lo] + a[hi];
            if (current == target){
                found = true;
            }
            if(Current < target){
                lo++;
            }
            else{
                hi--;
            }
        }
    }
    if(found)
    cout<<"True";
    else{
        cout<<"False";
    }return 0;
}

//maximum consecutive ones
/*given an array A of Os and 1s, we may change up to K values from 0 to 1.
return the length of the longest(contigous) sub array that contains only 1s*/
#include<iostream>
#include"bits/stdc++.h"
using namespace std;
int32_t main(){
    int n;
    cin>>k;
    vector<int> a(n);
    for(auto &i:a)
    cin>>i;
    int zerocnt = 0, i=0,ans=0;
    for(int j=0;j<n;j++){
        if(a[j]==0)
        zerocnt++;
        while(zerocnt > k){
            if(a[i] == 0){
                zerocnt--;
            }
            i++;
        }
        //zerocnt <=K
        ans = max(ans, j-i+1);
    }
    cout<<ans;
}

//longest substring without repeating charachter
/*given a string s, find the length of the longest substring without repeating characters*/
#include<iostream>
#include "bits/stdc++.h"
using namespace std;
int32_t main(){
    string s; cin>>s;
    vector<int> dict(256, -1);
    int maxLen = 0, sart = -1;
    for(int i=0; i<s.size(); i++){
        if(dict[s[i]] > start)
        start = dict[s[i]];
    dict[s[i]]== i;
    maxLen = max(maxLen, i-start);
    }
    cout<<mexLen;
}

