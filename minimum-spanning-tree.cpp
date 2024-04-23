//graphs
//Krushal's algorithm
/* given an undirected and connected graph G(V,E), a spanning tree of the graph G is a tree that spans G(tha is, it includes
every vetex of G) and is a subgraph of G(that is, i includes evry vertex of G) and is a subgraph of G(evevry edge in the tree belongs to G)*/

/* spanning tree- the cost of the spanning tree is the sum of the weights of all the edge in the tree
there can be many spanning tree.*/
/* minimum spanning tree:- minimum spanning tree is the spanning tree where the cost is minimum among all the spanning trees. there
 also can be many minimum spanning trees.*/
 /* Pseudocode: 1. sort the edges in increasing order of their weights.
                2. iterate in the sorted edges, if inclusion of i'th edge leads to a cycle then skip this edge. else include in the MST.

                Time complexity: o(E log V)
                space complexity: O(E+V)
                */
#include namespace std;
const int N = 1e5+6;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}             
int find_set(int v){
    if(v == parent[v])
    return v;
    return parent[v] = find_set(parent[v]);
}  
void union_sets(int a, int b){
    a= find_set(a);
    b= find_set(b);
    if(a !=b){
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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i =0; i<m; i++){
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(), edges.end());
    int cost = 0;
    for(auto i: edges){
        int w= i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u);
        int y = find_set(v);
        if(x==y){
            continue;        }
    else{
        cout<<u<<" "<<v<<"\n";
        cost += w;
        union_sets(u,v);
    }}
cout<<cost;}
//prims algorithm
/*idea- select an arbitary vertex s to start the tree from. while(there are still nontree vertices)
select the edges of minimum weight between a tree and nontree vertex.
add the selected edge and vertex to the tree.*/
#include "bits/stdc++.h"
using namespace std;
int n,m; const int N = 1e5 + 3;
vector<vector< int>> g[N];
int cost = 0;
vector<int> dist[N], parent[N];
vector<bool> vis[N];
const int INF = 1e9;
void primsMST(int source){
    for(int i =1; i<n;i++){
        dist[i] = INF;
            }
            set<vector<int>> s;
            dist[source] =0;
            s.insert({0,source});
            while(!s.empty()){
                auto x = *(s.begin());
                vis[x[1]] = true;
                int u = x[1];
                int v = parent[x[1]];
                int w = x[0];
                cout<<u<<" "<<w<<"\n";
                cout += w;
                for(auto it: g[x[1]]){
                    if(vis[it[0]])
                    continue;
                    if(dist[it[0]] > it[1]){
                        s.erase({dist[it[0]],it[0]});
                        dist[it[0]] = it[1];
                        s.insert({dist[it[0]],it[0]});
                        parent[it[0]] = x[i];
                    }
                }
            }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
            }
}

//Dijkstra's algorithm
/* Problem: gievn a weighted graph. Find the single source shortest path from a vertex u to all the vertices in the graph. if the node is unreachable
then print -1 
Note: the weights of the edges must be positive

idea:- Assign a distance value to all vertices in the input graph. initialize all distance values as INFINITE. Assign distance
value as 0 for the source vertex.
2. while set is not empty
A. pick a vertex u from set s that has minimum distance value.
B. update distance value of all adjacent vertices of u.*/
#include "bits/stdc++.h"
using anmespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> dist(n+1,inf);
    vector<vector<pair<int, int>> graph(n+1);
    for(int i= 0; i<m; i++){
        int u, v, w; cin>>u>>v>>w;
        graph[u]. push_back({v,w});
        graph[u].push_back({v,w});    }
int source; cin>>source;
dist[source] = 0;
set<pair<int,int>> s;
s.insert({0,source});
while(!s.empty()){
    auto x = *(s.begin());
    s.erase(x);
    for(auto i: graph[x.second]){
        if(dist[it.first]>dist[s.second] + it.second){
            s.erase({dist[it.first], it.first});
            dist[it.first] = dist[x.second] + it.second;
        }
    }
}
for(int i=1;i<n;i++){
    if(dist[i]<inf){
        cout<<dist[i]<<" ";
    }
    else{
        cout<<-1<<" ";
    }
}
}
//bellman ford theory
/*problem: from a source vertex v, find the shortest distance to all other nodes in the graph*/
/*idea: initially d[v] = 0 and for all other elements s[] = inf
in case pass, relax all the edges. i.e for edge(a,b) having weight w,
d[b] = min(d[b], d[a] + w)
assuming no negative edge contain cycle, since there are n verices, shortest path can only contain 'n-1' edges. therefore, we will
get our answer in at most 'n-1' passes */
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int src; cin>>src;
    vector<int> dist(n,INF);
    dist[src] = 0;
    for(int iter = 0; iter<n-1; iter++){
        for (auto e: edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[v] = min(dist[v],w + dist[u]);
        }
    }
    for(auto i: dist)
    cout <<i<<" ";
    cout<<"\n";
}
//floyd warshall algorithm
/*to find all pair shortest paths i.e for every u,v in graph G, find the shortest path from u to v. */
#include "bits/stdc++.h"
using namespace std;
const int INF = 1e9;
int main(){
    vector<vector<int>> graph = { {0,5,INF,10},
                                {INF,0,3,INF},
                                {INF,INF,0,1},
                                {INF,INF,INF,0}};
    int n= graph.size();
    vector<vector<int>> dist = graph;
    for(int k= 0; k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j=0;j<n; j++){
                if(dist[i][k] + dist[k][j]<dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j] == INF){
                cout<<"INF";
            }
            else
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }                            
}
// surrounded regions
/*problem:- given a 2D board containing 'X' and 'O' capture all regions surrounded by 'X'.
a region is captured by flipping all 'O' into 'X' in that surrounded region. */
/*idea:- traverse the 'O' components around the edges of the grid and changes it to '*'.
the remaining 'O' components will be surrounded regions that can be captured.
change the '*' back to 'O'. */
#include "bits\stdc++.h"
using namespace std;
void change(vector<vector<char>> &A, int x, int y){
    A[x][y] = '*';
    int dx[] = {0,0,-1,-1};
    int dy[] = {1,-1,0,0};
    for(int i =0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dx[i];
        if(cx>=0 and cx<A.sixe() and cy>=0 and cy<A[0].size() and A[cx][cy] == '0'){
            change(A,cx,cy);
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<char>> A(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 or i==n-1  or j==0 or j== m-1){
                change(A,i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == 'O'){
                a[i][j] = 'X';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == '*'){
                A[i][j] = 'O';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
}