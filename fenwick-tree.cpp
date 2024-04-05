//binary index tree
/* updates in binary tree:
range sum with point update
range sum with range updates*/
#include "bits/stdc++.h"
using namespace std;
int n;
vector<int> bit;
void update(int idx,int val){
    while(idx<=n){
        bit[idx] += val;                    //range with point update
        idx += idx &(-idx);
    }
}
int query(int i,i){
    int ans = 0;
    while(idx >0){
        ans += bit[idx];
        idx -= idx &(-idx);
    }return ans;
}
int main(){
    cin>>n;
    bit=vector<int>(n+1);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int q;cinn>>q;
    while(q--){
        int c;cin>>c;
        if(c==1){
            int l,r;cin>>l>>r;
            int ans = query(r) - query(l-1);
            cout<<ans<<"\n";
        }
        else if(c==2){
            int index,val;
            cin>>index>>val;
            update(index,-a[index]);
            a[index] = val;
            update(index,val)
        }
    }
}

#include "bits/stdc++.h"
using namespace std;
int query(int i, int bit[], int n){
    int ans =0;
    while(i>0){
        ans+=bit[i];
        i-=i & (-i);
    }
}
void update(int i,int inc,int bit[],int n){                 //range sum with range updates
    while(i<=n){
        bit[i] += inc;
        i+=i & (-i);
    }
}
int main(){
 int t;cin>>t;
 while(t--){
    int n;cin>>n;
    int bit[n+10] = {0};
    int u,cin>>u;
    while(u--){
        int l, r,inc;
        l++;r++;
        update(l,inc,bit,n);
        update(r+1,-inc,bit,n);
    }
    int q;cin>>q;
    while(q--){
        int w;cin>>w;
        w++;
        cout<<query(w,bit,n)<<"\n";
    }
 }   
}
//count Inversions using fenwick tree
/* count the inversions in the given array.
two elements a[i] and a[j] form an inversion if a[i] > a[j] and i<j*/
#include "bits/stdc++.h"
using namespace std;
vector<int>bit;
int getSum(int idx){
    int sum = 0;
    while(idx > 0){
        sum += bit[idx];
        idx -= idx & (-idx);
    }return sum;
}
void update(int n,int idx, int inc){
    while(idx<=n){
        bit[idx] += inc;
        idx += idx & (-idx);
    }
}
int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(auto &i : a)
    cin>>i;
    vector<int> temp=a;
    sort(temp.begin(),temp.end());
    for(int i = 0;i<n;i++){
        a[i] = lower_bound(temp.begin(),temp.end(),a[i]) - temp.begin() + 1;
    }
    bit = vector<int>(n+1);
    int inv = 0;
    for(int i = n-1; i>=0;i--){
        inv += getSum(n, a[i], 1);
    }
    cout<<inv;
}
//sequence root decomposition
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 1e5+2, MOD = 1e9+7;
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int len = sqrtl(n) +1;
    vector<int> b(len);
    for(int i=0; i<n;i++){
        b[i/len] += a[i];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r; 
        l--;r--;
        for(int i=l; i<=r;){
            if(i%len == 0 && i+len-1 <= r){
                sum += b(i/len);

                i+= len;
            }
            else{ sum += a[i];
            i++;}
        }   }cout<<sum<<endl;
return 0;
}
//RMQSQ-SPOJ QUESTION (using SQRT decomposition)
/* you are given a list of N numbers and Q queries is specified by two numbers the ansswer to each query is the minimum number between the range
[i,j]  the query ranges are specified using 0-based indexing*/
#include "bits/stdc++."
using namespace std;
#define int long long
const int N = 1e5+2, MOD = 1e9+7;
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    cin>>a[i];
    int len= sqrt(n) +1;
    vector<int> b(len, MOD);
    for(int i=0; i<n; i++){
        b[i/len] = min(b[i/len], a[i]);
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans = MOD;
        for(int i=l;i<=r;){
            if(i%len == 0 && i+len-1 <=r){
                ans = min(ans, b[i/len]);
                i+=len;
            }else{ ans= min(ans, a[i]);
            i++;}
        }cout<<ans<<endl;    }
    return 0;
}
//Mo's Algorithm
/* you are given an array of size n and q queries. each query is a range query. In each query, we have to perform
some operation and output answer of each query*/
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 1e5+2, MOD = 1e9+7;
int rootN;
struct q{
    int idx, l,r;
};
Q q[N];
bool compare(Q q1,Q q2){
    if(q1.l/rootN == q2.l/rootN){
        return q1.r>q2.r;
    }return q1.l/rootN <q2.l/rootN;
}
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    rootN = sqrtl(n);
    int queries;
    cin>>queries;
    for(int i=0; i<queries; i++){
        int l, r;
        cin>>l>>r;
        q[i].l=l;
        q[i].r=r;
        q[i].idx = i;
    }
    sort(q, q+queries, compare);
    vector<int> ans(queries);
    int curr_l=0, curr_r = -1,l,r;
    int curr_ans = 0;
    for(int i=0; i<queries; i++){
        l=q[i].l;r=q[i].r;
        l--;r--;
        while(curr_r<r){
            curr_r++;
            curr_ans += a[curr_r];
        }
        while(curr_l>l){
            curr_l--;
            curr_ans += a[curr_l];
        }
        while(curr_l<l){
            curr_ans -= a[curr_l];
            curr_l++;
        }
        while(curr_r>r){
            curr_ans -= a[curr_r];
            curr_r--;
        }ans[q[i].idx]=curr_ans;}for(int i=0;i<queries; i++){
           cout<<ans[i]<<endl;
        }
    
    return 0;}
//DQUERY-SPOJ QUESTION (using Mo's algorithm)
/* Given a sequence of numbers a1,a2,...an and a number of d-queries. A d-query is a pair(i,j)(1<=i<=j<=n).
for each d-query(i,j), you have to return the number of distinct elements in the subsequence ai,ai+1,...aj. */
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 2e5+2, MOD = 1e9+7;
struct Q{
    int l,r,idx;
};
int rootN;
Q q[N];
bool compare(Q q1, Q q2){
    if(q1.l/rootN == q2.l/rootN){
        return q1.r>q2.r;
    }return q1.l>q2.l;
}
signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
          q[i].l=l;
        q[i].r=r;
        q[i].idx = i;   }
        sort(q,q+n,compare);
        vector<int> ans(queries);
        int cur_l=0, cur_r=1, l, r;
        int curr_ans = 0;
        vector<int> freq(10*N, 0);
        for(int i=0; i<queries; i++){
            l=q[i].l; r=q[i].r;
            l--; r--;
            while(cur_r < r){
                cur_r++;
                freq[a[cur_r]]++;
                if(freq[a[curr]] ==1)
                curr_ans++;
            }while(cur_l < l){
                freq[a[cur_r]]--;
                cur_r--;
            }ans[q[i].idx] = curr_ans;}
            for(int i=0; i<queries; i++){
                cout<<ans[i]<<endl;
            }
        return 0;
}