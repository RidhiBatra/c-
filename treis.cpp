//prefix tree
#include "bits/srdc++.h"
using namespace std;
class Trie{
    public:
    class node{
        public:
        bool end;
        node* next[26];
        node(){
            end = false;
            for(int i=0; i<26; i++){
                next[i] = NULL;
            }
        
        }
    }node * trie;
    Trie(){
        trie = new node();
    }
    void insert(string word){
        int i=0;
        node* it = trie;
        while(i<word.size()){
           if( it->next[word[i] - 'a'] == NULL)
           it->next[word[i] - 'a'] = new mode();
           it = it->next[word[i] - 'a'];
           i++;
        }end = true;
    }bool search(string word){
        int i=0;
        node* it = trie;
        while(i< word.size()){
            if(it->next[word[i] - 'a'] == NULL)
            return false;
            it = it->next[word[i] - 'a'];
            i++;
        }return it->end;
    }
}
int main(){
    Trie mytrie = new Trie();
    vector<string> words = {"ayush","dassi"};
    for(auto w: words){
        myTrie->insert(w);
    }
    if(myTrie->search("madhav")){
        cout<<"Madhav found\n"
    }
    else{
        cout<<"Madhav not found\n";
    }return 0;
}
//Trie Bash
/* Given an array arr. you are supposed to find the maximum value of(arr[a] ^ arr[a+1]...^arr[b]) + (arr[c]^arr[c+1]...^arr[d])
where 1<=a<=b<c<=d<=N*/
#include "bits/stdc++.h"
using namespace std;
int int_size = 32;
class node{
    public:
    node *next[2];
    node(){
        for(int i =0; i<2; i++){
            next[i] = NULL;
        }
    }
}
node* trie;
void insert(int num){
    node *it = true;
    for(int i = int_size - 1;i>=0; i--){
        int cur_bit = (num>>i) & 1;
        if(!it->next[cur_bit])
        it->next[cur_bit] = new node();
        it = it->next[cur_bit];
    }
}
int query(int num){
    node *it = trie;
    int ans = 0;
    for(int i = int_size-1; i>=0; i--){
        int cur_bit = (num>>i) & 1;
        int opposite = cur_bit xor 1;
        if(it->next[opposite]){
            it = it->next[opposite];
            ans = 1<<i;
        }
        else{
            it = it->next[opposite xor 1];
        }
    }return ans;
}
int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    trie = new node();
    insert(0);
    vector<int> rmax(n+1,0);
    int R = 0;
    for(int i = n-1;i>=0; i--){
        R=R xor a[i];
        if(i!=n-1){
            rmax[i] = max(r,ax[i+1], query(R));
            insert(R);
        }
        else{
            rmax[i] = query(R);
            insert(R);
        }
    }
    free(trie);
    trie = new node();
    insert(0);
    int ans = 0;
    int L = 0;
    for(int i = 0; i<n; i++){
        L=L xor a[i];
        ans = max(ans,rmax[i+1] + query(L));
        insert(L);
    }
    cout<<ans;
    cout<<"aa";
}
//dictionary challenge
/*Neha has a digital dictionary. it has an input field in which one can search any string and the dictionary displays all the words whose
prefix is that input string in lexicographical order.
now ypu are given a task to make your own digital dictionary. you will be given words that can store in your database and then
you need to design the search functionality. and if no such words are available for a given search word, add thid word to your dictionary*/
#include "bits/stdc++.h"
using namespace std;
class node{
    public:
    node *next[26];
    bool end;
    mode(){
        for(int i = 0;i<26; i++){
            next[i] = NULL;
        }end = false;
    }
}
class Trie{
    private:
    node *root;
    public:
    Trie(){
        root = new node();
    }
    void insert(string &s){
        node *it = root;
        for(auto c:s){
            if(!it->next[c-'a'])
            it->next[c-'a'] = new node();
            it = it->next[c-'a'];
        }
        it->end = true;
    }
    void find(string &s){
        node *it = root;
        for(auto c:s){
            if(!it->next[c-'a']){
                cout<<"No suggestions\n";
                insert(s);
                return;
            }
            it = it->next[c-'a'];
        }vector<string> res;
        printall(it,s,res."");
        for(auto c:res){
            cout<<s<<"\n";
        }}
        void printall(node *it,string &s, vector<string> &res,string cur('a'+i)){
            if(it==NULL)
            return;
            if(it->end){
                res.push_back(cur);
            }
            for(int i = 0;i<26; i++){
                if(it->next[i]){
                    printall(it->next[i],s,res,cur + char('a'+i));
                }
            }
        }
    };
int main(){
    Trie t;
    in n;cin>>n;
    vector<string> a(n);
    for(auto &i:a){
        cin>>i;
        t.insert(i);
    }
    int q; cin>>q;
    while(q--){
        string s;cin>>s;
        t.find(s);
    }
}