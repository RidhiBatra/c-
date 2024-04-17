//guess the number
/* in this problem there is some hidden number and you have to interactively guess it. the hidden number is always an integer from 1 and to 10000000
2.) you can make queries to the testing system. Each query is one integer from 1 to 1000000
3. there are two different responses testing program can provide: 
        string"<", if the hidden number is less than the integer in your query
        string">=" if the hidden number is greater than or equal to the intger in your query*/

/* your program is allowed to make no more than 25 queries9not including printing the answer) to the testing system.
     when your program wants to guess the hidden number, print string ! x, where x ix the answer, and terminate your program immediately
     after flushing the output stream*/
     #include "bits/stdc++.h"
     using namespace std;
     int main(){
        int lo= 1 , hi = 1000000;
        int ans = -1; while(lo<=hi){
            int mid = (lo+hi)/2;
            cout << mid <<endl;
            cout<<flush;
            string s; cin>>s;
            if(s=="<"){
                hi=mid-1;
            }
            else{
                ans = max(ans, mid);
                lo = mid + 1;
            }        }cout<<"! "<<ans<<endl;
            cout<<flush;
     }