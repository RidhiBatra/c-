//stack data structure
//stores a list of items in which an item can be added or removed from the list only at the end.
//based on lifo mechanism(last in first out)
#include<iostream>
using namespace std;
#define n 100
class stack{
    int* arr;
    int top;
    public:
    stack(){
        arr=new int[n];
        top=-1
    }
    void push(int x){
        if(top==n-1){
            cout<<"stack overflow"<<end l;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<" no element to pop"<<endl;
            return;
        }
        top--;
    }
    int Top(){
        if(top==-1){
            cout<<"no element in stack"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;    }
};
int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.empty()<<endl;
    return 0;
}

//reverse a challenge
#include<iostream>
#include<stack>
using namespace std;
void reverseSentence(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word=" ";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}
int main(){
    string s= "Hey, how are you doing?";
    reverseSentence(s);
}

//reverse a stack
#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele=st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(topele);
}
void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, ele);
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }cout<<endl;
}

//inflix   <operand><operator><operand>
//prefix    polish notation  <operator><operand><operand>
//postflix   reverse polish notation   <operand><operand><operator>

//prefix expression evaluation
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int prefixEvaluation(string s){
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            switch (s[i]){
                case '+':
                st.push(op1+op2);
                break;
                case '^':
                st.push(pow(op1,op2));
                break;
                case '-':
                st.push(op1-op2);
                break;
                case '*':
                st.push(op1*op2);
                break;
                case '/':
                st.push(op1/op2);
                break;
            }
        }
    }return st.top();
}
int main(){
    cout<<prefixEvaluation("-+7*45+20")<<endl;
    return 0;
}

//postfix expression evaluation
#include <iostream>
#include<math.h>
#include<stack>
using namespace std;
int postfixEvaluation(string s){
    stack<int> st;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='0' && s[i]-'9'){
            st.push(s[i]-'0');
        }
        else{
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            switch(s[i])
            {
                case '+':
                st.push(op1+op2);
                break;
                case '^':
                st.push(pow(op1,op2));
                break;
                case '-':
                st.push(op1-op2);
                break;
                case '*':
                st.push(op1*op2);
                break;
                case '/':
                st.push(op1/op2);
                break;
            }
        }
    }return st.top();

}
int main(){
    cout<<postfixEvaluation("46+2/5*7+")<<endl;
    return 0;
}

//infix to postfix
#include<iostream>
#include<stack>
using namespace std;
int prec(char c){
    if(c=='^'){return 3;}
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }        
    else{return -1;}
    
}
string infixtoPostfix(string s){
    stack<char> st;
    string res;
    for(int i=0; i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty()  && prec(st.top())>prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}
int main(){
    cout<<infixtoPostfix("(a-b/c)*(a/k-l)")<<endl;
}

//infix to prefix
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='/' || c=='*'){
        return 2;
    }
    else if(c=='-'||c=='+'){
        return 1;
    }
    else{
        return -1;
    }
}
string infixToPrefix(string s){
    reverse(s.begin(),s.end());
    stack<char> st;
    string res;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='a'&&s[i]<='z' || (z[i]>='A'&& s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while(!=st.empty() && st.top()!=')'){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>=pres(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.endl());
    return res;
}
int main(){
    cout<<infixToPrefix("(a-b/c)*(a/k-l)")<<endl;
}


//balanced paranthesis
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isValid(string s){
    int n = s.size();
    stack<char> st;
    bool ans =true;
    for(int i=0; i<n; i++){
        if(s[i] == '{' or s[i] == '(' or s[i] == '['){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!st.empty() and st.top() == '('){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(s[i] == '['){
            if(!st.empty() and st.top() == ']'){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(s[i] == '{'){
            if(!st.empty() and st.top() == '}'){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
    }
    if(!st.empty())
    return false;
    return ans;

}
int main(){
    string s="{([])}";
    if(isValid(s)){
        cout<<"Valid String"<<endl;
    }
    else{
        cout<<"Invalid string"<<endl;
    }
    return 0;
}