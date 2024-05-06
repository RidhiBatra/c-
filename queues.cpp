//queues is a inear data structure that stores the data in first in first out fashion
//queues using arrays
class queue{
    int* arr; int front; ; int back;
    public:
    queue(){
        arr= new int[n]; front = -1; back = -1;
    }
    void push(int x){
        if(back == n-1){
            cout<< "Queue overflow" << endl;
            return ;
        }
        back++;
        arr[back] = x;
        if(front == -1){
            front++;
        }
    }
    void pop(){
        if (front == -1 || front>back){
            cout << "No elements in Queue" <<endl;
            return;
        }
        front++;
    }
    int peek(){
        if(front == -1 || front>back){
            cout << "No elements in Queue"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        if (front == -1 || front >back){
            return true;
        }
        return false;
    }
};
int main(){
    queue q;
    q.push(1);
     q.push(2);
      q.push(3);
       q.push(4);
    cout<< q.peek() <<endl;
    q.pop();   
}

//queue using linked list
class node{
    public:
    int data;
    node* next;
    node(int val){
        data= val;
        next= NULL;
    }
};
class queue{
    node* front; node* back;
    public:
    queue(){
        front = NULL; back = NULL;
    }
    void push(int x){
        node* n = new node(x);
        if (front == NULL){
            back= n;
            front = n;
            return;
        }
        back->next = n;
        back= n;
    }
    void pop(){
        if (front == NULL){
            cout<< "Queue underflow" << endl;
            return;
        }
        node* todelete = front;
        front = front->next;
        delete todelete;
    }
    int peek(){
        if(front == NULL){
            cout << "no element in Queue" << endl;
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front == NULL)
        return true;
        return false;
    }
};

//stack using Queue
class stack{
    queue<int> q;
    public:
    void push(int x){
        queue<int> temp;
        temp.push(x);
        while (!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        swap(q, temp);
    }
    void pop(){
        q.pop();
    }
    int peek(){
        return q.front();
    }
    bool empty(){
        return q.empty();
    }
};

//Queue using stack
'''there are two types:
Enqueue costly
Dequeue costly'''

class queue {
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        while (s1.empty() && s2.empty()){
            cout<<"Queue is empty" << endl;
            return -1;
        }
        if(s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topvalue = s2.top();
        s2.pop();
        return topvalue;
    }
    bool empty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }
};

//deque data structure
#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    for(auto i: dq)
    cout<<i<<" ";
    cout<<"\n";
    dq.pop_back();
    dq.pop_front();
    for(auto i : dq)
    cout<< i <<" ";
    cout<<"\n";
    cout<<dq.size();
}

//sliding window maximum
#include <iostream>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(auto &i: a)
    cin>>i;
    '''multiset<int, greater<int>> s;
    vector<int> ans;
    for(int i=0;i<k;i++){
        s.insert(a[i]);
    }
    ans.push_back(*s.begin());
    for(int i =k; i<n; i++){
        s.erase(s.lower_bound(a[i-x]));
        s.insert(a[i]);
        ans.push_back(*s.begin());
            }
            for(auto i: ans)
            cout<<i<<" ";
}'''

//in dequeue
deque<int> q;
vector<int> ans;
for(int i=0; i<k;i++){
    while(!q.empty() and a[q.back()]< a[i]){
        q.pop_back();
    }
    q.push_back(i);
}
ans.push_back(nums[q.front()]);
for(int i=k; i<n;i++){
    if(q.front() == i-k){
        q.pop_front();
    }
    while(!q.empty() and a[q.back()] < a[i]){
        q.pop_back();
    }
    q.push_back(i);
    ans.push_back(a[q.front()]);
}
for (auto i: ans)
cout<< i<<" ";
}

//largest rectangle in a histogram
''' given an array. Each element represents the height to the histograms bar and the width of each bar
is 1, find the area of largest rectangle in the histogram'''
#include<iostream>
#include "bits/stdc++.h"
using namespace std;
int get_max_area(vector<int> a){
    int n = a.size(), ans =0, i=0;
    a.push_back(0);
    while(i<n){
        while(!st.empty() and a[st.top()] > a[i]){
            int t =st.top();
            int h = a[t];
            st.pop();
            if(st.empty()){
                ans = max(ans, h*i);
            }
            else{
                int len= i- st.top() -1;
                ans= max(ans,h * len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}