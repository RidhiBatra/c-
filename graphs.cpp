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
const int N = 1e5+2, MOD = 1e9+7;
signed main(){
    int n, m;
    cin>>n>>m;
    vvi adjm(n+1, vi(n+1,0));
    rep(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        adjm[x][y] =1;
        adjm[y][x]=1;
    }
    cout<<"adjacency matrix of above fraph is given by: "<<endl;
    rep(i,1,n+1)
    {
        cout<<i<<"->";
        for(int x: adj[i].begin(); it!=adj[i].end(); it++)
        cout<<*it<<" ";
        cout<<endl;
    }return 0;
}
//representation of graph
#include "bits/stdc++.h"
using namespace std;
 const int N = 1e5+2;
 bool vis[N];
 vector<int> adj[n];
 int main(){
    for(int i=0; i<N; i++)
    vis[i] = 0;
    int n, m;
    cin>>n>>m;
    int x,y;
    for(int i=0; i<m; i++){
        cin >> x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<endl;
        vector<<node<<endl;
        vector<int> :: iterator it;
        for(it = adj[node].begin(); it!= adj[node].end(); it++){
            if(!vis[*it]){
                vis[*it]=1;
                q.push(*it);
            }
        }
    }return 0;
 } 
 //preorder,postorder,inorder
 #include "bits/stdc++.h"
 using namespace std;
 const int N = 1e5+2;
 bool vis[N];
 vector<int> adj[N];
 void dfs(int node)
 {
    //preorder
    vis[node] = 1;
    cout<<node<<" ";
    //inorder
   vector<int> :: iterator it;
   for(it =adj[node].end(); it++){
    if(vis[*it]);
    else{
        dfs(*it);
    }
   } 
   //postorder
   cout<<node<<" ";
 }
 int main(){
    int n,m; cin>>n>>m;
    for(int i=0; i<=n; i++)
vis[i] = false;
int x,y;
for(int i=0; i<m; i++)
{
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}return 0; 
}
//topological Sort
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n, m;cin>>n>>m;
    int cnt = 0;
    vector<vector<int>> adj_list(n);
    vector<int> indeg(n,0);
    for(int i=0;i<m; i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> pq;
    for(int i=0;i<n;i++){
        if(indeg[i] == 0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        cnt++;
        int x = pq.front();
        pq.pop();
        cout<<x<<" ";
        for(auto it: adj[x]){
            indeg[it]--;
            if(indeg[it] == 0)
            pq.push(it);
        }
    }
}
//cycle detection
#include "bits/stdc++.h"
using namespace std;
bool iscycle(int src, vector<vector<int>> &adj, vector<bool> &visited, int parent){
    visited[src] = true;
    for(auto i: adj[src]){
        if( i!=parent){
        if(visited[i])
        return true;
        if(!visited[i] and iscycle(i, adj, visited)){return true;}
    }}return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle = false;
    vector<bool> visited(n,false);
    for(int i=0;i<n; i++){
        if(!visited[i] and iscycle(i,adj,visited, -1)){
            cycle=true;
        }
    }
    if(cycle)
    cout<<"cycle is present";
    else{
        cout<<"cycle is not present";    }
}
//cycle detection in a directed graph
#include "bits/stdc++.h"
using namespace std;
bool iscycle(int src, vector<vector<int>> &adj,vector<bool> &visited, vector<int> &stack){
    stack[src] = true;
    if(!visited[src]){
        visited[src] = true;
        for(auto i: adj[src]){
            if(!visited[i] and iscycle(i, adj, visited, stack)){
                return true;
            }
            if(stack[i])
            return true;
        }
    }
    stack[src] = false;
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }bool cycle = false;
    vector<int> stack(n,0);
    vector<bool> visited(n,0);
    for(int i =0;i<n;i++){
        if(!visited[i] and iscycle(i,adj,visited,stack)){
            cycle = true;
        }
    }
    if(cycle)
    cout<<"cycle is present";
    else{
        cout<<"cycle is not present";
    }
}

//connected components
#include "bits/stdc++.h"
using namespace std;
vector<bool> vis;
int n,m;
vector<vector<int>> adj;
vector<int> components;
int get_comp(int idx){
    if(vis[idx])
    return 0;
    vis[idx] = true;
    int ans = 1;
    for(auto i: adj[idx]){
        if(!vis[i]){
            ans+= get_comp(i);
            vis[i] = true;
        }
    }return ans;
}
int main(){
    cin>>n>>m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<n;i++){
        components.push_back(get_comp(i));
    }
}
for(auto i: components){
    cout<<i<<" ";
}
//Bipartite graph
#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool bipart;
void color(int u,int curr){
    if(col[u] != -1 and col[u] != curr){
        bipart = false;
        return;
    }
    col[u] = curr;
    if(vis[u])
    return;
    vis[u] = true;
    for(auto i: adj[u]){
        color(i, curr xor 1);
    }
}
int main(){
    bipart = true;
    int n,m; cin>>n>>m;
    adj= vector<vector<int>>(n);
    vis= vector<bool>(n,false);
    col = vector<int>(n,-1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            color(i,0);
        }
    }
    if(bipart)
    cout<<"graph is bipart";
    else{ 
        cout<<"graph is not bipartite"
    }
}
//union find
//cycle detection in a unidirected graph using DSU
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5+6;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v){
    parent[v] = v;
    sz[v] =1;
}
int find_set(int v){
    if(v== parent[v])
    return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b){
    a=find_set(a);
    b=find_set(b);
    if(a != b){
        if(sz[a] < sz[b])
        swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int main(){
    for(int i=0; i<N; i++){
        make_set(i);
    }
    int n,m;cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        edges.push_back({u,v});
    }
    for(auto i: edges){
        int u= i[0];
        int v = i[1];
        int x = find_set(u);
        int y = find_set(v);
        if(x==y){
            cycle = true;
        }
        else{
            union_sets(u,v);
        }
    }
    if(cycle)
    cout<<"cycle is present";
    else{
        cout<<"does not contain a cycle"<<" ";
    }
}