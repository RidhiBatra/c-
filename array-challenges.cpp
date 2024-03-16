//max till i
#include <iostream>
using namespace std; 
int main(
    int mx = -19999999;
    int n;
    cin>> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(int i=0; i<n; i++)
    {
        mx= max(mx, a[i]);
        cout <<mx << endl;
    }
    return 0;
)




//sum of all subarrays
#include <iostream>
#include "bits/stdc++.h"
using namespace std; 
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int curr =0;
    for(int i=0; i<n; i++)
    {
        curr=0
        for(int j=i; j<n;j++)
        {
            curr+=a[j];
            cout << curr << endl;
        }
    }
    return 0;
)




//longest arithmatic subarrays
#include <iostream>
#include " bits/stdc++.h"
using namespace std; 
int main(
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++)
    {
        cin>> a[i];
    }
    int ans=2;
    int pd= a[1]-a[0];
    int j=2;
    int curr =2;
    while(j<n)
    {
        if(pd == a[j]-a[j-1])
        {
            cur++;
        }
        else{
            pd= a[j]-a[j-1];
            curr=2;}
            ans = max(ans,curr);j++;
    }
cout << ans << endl;
return 0;
}



//record breaker
#include <iostream>
include " bits/stdc++.h"
using namespace std; 
int main(){
    int n;
    cin>> n;
    int a[n+1];
    a[n]= -1;
    for(int i=0; i<n; i++)
    {
        cin>> a[i];
    }
    if(n==1)
    {
        cout <<"1"<<endl;
        return 0;
    }
    int ans=0;
    int mx =-1;
    for(int i=0; i<n;i++)
{
    if(a[i]>mx && a[i]>a[i+1]){
        ans++;
    }
    mx = max(mx,a[i]);
}cout << ans <<endl;
return 0;
}


//first repeating element
#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>> n;
    int a[n];
    for(int i=0;i<n; i++)
    {

        cin>> a[i];
    }
    const int N = 1e6+2;
    int idx[N];
    for(int i=0; i<N; i++)
    {
        idx[i] = -1;
    }
    int minidx = INT_MAX;

    for(int i=0; i<n; i++)
    {
        if(idx[a[i]] != -1)
        {
            minidx = min(minidx, idx[a[i]];)
        }else{
            idx[a[i]] =i;
        }
    }
    if(minidx == INT_MAX)
    {
        cout << "-1" << endl;
    }else{
        cout << minidx + 1 << endl;
    }return 0;
}


//Subarray with given sum
#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n, s;
    cin>> n>> s;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int i=0, j=0, st=-1, en=-1, sum=0;
    while(j<n && sum+a[j] <= s)
    {
        sum += a[j];
        j++;
    }
    if(sum == s){
        cout << i+1 << " " << j<<endl;
        return 0;
    }
    while (j<n){
        sum += a[j];
        while(sum > s){
            sum -= a[i];
            i++;
        }
        if(sum == s)
        {
            st= i+1;
            en= j+1;
            break;
        }
        j++;
    }
    cout << st << " "<< en << endl;
    return 0;
}


//smallest positive missing number
#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    const int N = 1e6 +2;
    bool check[N];
    for(int i=0; i<N; i++)
    {
        check[i]= 0;
    }
    for(int i=0; i<n; i++)
    {
        if(a[i] >= 0)
        {
            check[a[i]] = 1;
        }
    }int ans = -1;
    for(int i=1; i<N; i++)
    {
        if(check[i] == 0)
        {ans=i;
        break;
        }
    }
    cout << ans << endl;
    return 0;
}


//maximum subarray sum
#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>> arr[i];
    }
    int maxSum= INT_MIN;
    for(int i=0; i<n; i++){
        for(int i=0; i<n; i++){
            for(int j=i; j<n;j++){
                int sum=0;
                for(int k=i; k<=j; k++){
                    sum +=arr[k];}
                    maxSum= max(maxSum,sum);
                }
            }
        }cout<<maxSum<<endl;
        return 0;
    }




    //KADANE'S ALGORITHM
    
#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>> arr[i];

    }
    int currentSum=0;
    for(int i=0; i<n; i++)
    {
        currentSum+=arr[i];
        if(currentSum<0){
            currentSum=0;
        }maxSum=max(maxSum, currentSum);
    }cout<<maxSum<<endl;
    return0;
}

//pair sum problem
//check if there exists two elements in an array such that their sum is equal to given k
#include <iostream>
using namespace std;
bool pairsum(int arr[], int n , int k){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n; j++){
            if(arr[i]+arr[j]==k){
                cout<<i<<" "<<j<<endl;
                return true;
            }
        }
    }return false;
}
int main(){
    int arr[]={2,4,7,11,14,16,20,21};
    int k=31;
    cout<<pairsum(arr,8,k)<<endl;
    return 0;
}

