//play with elements indices
/* 1. transverse the whole array
   2. thodi si extra memory ke dam pe elements aur indices ko map kare*/
   /* problem: storing indices of such large elements cuz array's limit is only 10^8(that too global)*/
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

signed main(){
    map<int, int> m;
    m[8] = 2;
    cout < m[8] << endl;
    return 0;
}   
//hashing count frequency of elements in a given array
signed main(){
    int n;
    cin>> n;
    vi a(n);
    for(int i=0; i<n; i++)
    cin>> a[i];
    map<int, int> freq; 
    rep(i, 0, n){
        freq[a[i]]++;
    }
    map<int, int> :: iterartor it;
    for(it = freq.begin(); it!=freq.end(); it++)
    {
        cout << it->ff << " "<<it->ss << endl;
    }
return 0;
}
//print vertical order od a binary tree
struct Node{
    int key;
    Node *left, *right;
};
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
void getVerticalOrder(Node* root, int hdis, map<int, vi> &m)
{
    if(root == NULL)
    return ;
    m[hdis].push_back(root->key);
    getVerticalOrder(root->left, hdis-1, m);
    getVerticalOrder(root->right, hdis+1, m);
}

signed main(){
    Node *root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(4);
    root->left->right = newNode(11);
    root->left->left = newNode(3);
    root->right->left= newNode(14);
    root->right->right= newNode(6);
    <map<int, vector<int> > m;
    int hdis = 0;
    getVerticalOrder(root, hdis, m);
    map<int, vi> :: iterator it;
    for(it = m.begin(); it!=m.end(); it++){
        for(int i=0; i<(it->ss).size(); i++)
        {
            cout << (it->ss)[i] << " ";
        }cout << endl;
    }return 0;
}
//count Number of subarrys with sum zero
/* so we have to: map prefix sum to a map
2. for every key, choose 2 values from all the occurance of a particular prefsum("MC2").
3. specail case: for prefsum 0, we have to also include them*/
signed main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n)
    cin>>a[i];
    map<int, int> cnt;
    int prefSum = 0;
    rep(i, 0, n){
        cin >> a[i];
        map<int, int> cnt;
        int prefSum = 0;
        rep(i,0, n)
        {
            prefSum += a[i];
            cnt[prefSum]++;
        }
        int ans=0;
        map<int,int> :: iterator it;
        for(it = cnt.begin(); it!=cnt.end(); it++)
        {
            int c = it->ss;
            ans += (c*(c-1))/2;
            if(it->ff==0)
            ans += it->ss;
        }
        cout << ans << endl;
    }return 0;
}

//sliding window technique (min sum of k consecutive element)
/* we are given an array with n elements, calclate the minimum sum of k, consecuive elements*/
/*Brute force- Iterate from i=0 to i=n-k-1 in outer loop
statring from every j=i computer sum of k elements and maintain the minimum*/
signed main(){
    int n,k;
    cin>> n >> k;
    vi a(n);
    rep(i,0,n)
    cin>> a[i];
    int s=0, ans = INT_MAX;
    rep(i,0,k){
        s+=a[i];
    }
    cout << s << " ";
    ans = min(ans, s);
    rep(i,1,n-k+1){
        s -= a[i-1];
        s += a[i+k-1];
        ans = min(ans,s);
     cout << ans << " ";}
     cout <<endl;
     cout<< ans << endl;
    return 0;
}
// top k most frequent elemnt in the stream
signed main(){
    int n, k;
    cin >> n>> k;
    vi a(n);
    rep(i,0,n){
        cin>> a[i];
    }
    map<int, int> freq;
    rep(i,0,n){
        int presentSize = freq.size();
        if(freq[a[i]] == 0 && presentSize == k)
        break;
        freq[a[i]]++;
    }
    vii ans;
    map<int, int>:: iterator it;
    for(it = freq.begin(); it!=freq.end(); it++){
        if(it->ss != 0){
            pii p;
            p.ff = it-> ss;
            p.ss = it->ff;        
        ans.push_back(it->ss, it->ff);
            }    }
    sort(ans.begin(), ans.end(), greater<pii>());
    vii :: iterator it1;
    for(it1 = ans.begin(); it1!=ans.end(); it1++)
    {
        cout << it1->ss << " "<<it1->ff <<endl;
    }return 0;
}