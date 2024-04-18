#include<iostream>
#include "bits/stdc++.h"
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data= val;
        left = NULL;
        right = NULL;
    }
};
void printLevelOrder(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        if(node != NULL){
            cout<<node->data<<" ";
            if(node->left)
              q.push(node->left);
            if(node->right)
               q.push(node->right);  
        }
        else if(!q.empty())
        q.push(NULL);
    }
}
int main(){
    Node *root = new Node(1);
    root->left= new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printLevelOrder(root);
}

//find the sum of nodes at Kth level
int sumAtK(Node* root, int K){
    if(root == NULL){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level 0;
    int sum = 0;

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
           if(level == K){
            sum+= node->data;
           }
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        else if(!q.empty())
        q.push(NULL);
        level++;
    }return sum;
}
int main(){
    Node *root = new Node(1);
    root->left= new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<sumAtK(root, 2);}

    //count all the nodes in a Binary Tree
    int countNodes(Node* root){
        if(root == NULL){
            return 0;
        }
        return countNodes(root->left)+ countNodes(root->right) +1;
    }
    int main(){
        Node* root = new Node(1);
        root->left = new Node(2);
         root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<countNodes(root)<<"\n";
    return 0;
    }

    //sum all the nodes in a binary tree
    int sumNodes(Node* root){
        if(root == NULL){
            return 0;
        }
        return sumNodes(root->left) + sumNodes(root->right) + root->data;
    }
    int main(){
        Node* root = new Node(1);
        root->left = new Node(2);
         root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<sumNodes(root)<<"\n";
    return 0;
    }

    //height and diameter in binary tree
    /*height - it is the depth of the tree's deepes node*/
    int calcHeight(Node* root){
        if(root == NULL){
            return 0;
        }
        int lHeight = calcHeight(root->left);
        int rHeight = calcHeight(root->right);
        return max(lHeight, rHeight) + 1;
    }
    int main(){
        Node* root = new Node(1);
        root->left = new Node(2);
         root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<calcHeight(root)<<" \n";
    return 0;
    }
    /* diameter- number of nodes in the longest path between any two leaves*/
    int calcHeight(Node* root){
        if(root == NULL){
            return 0;
        }return max(calcHeight(root->left), calcHeight(root->right)) +1;
    }
    int calcDiameter(Node* root){
        if(root == NULL){
            return 0;
        }
    }
    int calcDiameter(Node* root){
        int lHeight = calcHeight(root->left);
        int rHeight = calcHeight(root->right);
        int currDiameter = lHeight + rHeight +1;

        int lDiameter = calcDiameter(root->left);
        int rDiameter = calcDiameter(root->right);
        return max(currDiameter, max(lDiameter, rDiameter));
    }
    int main(){

    
    Node* root = new Node(1);
        root->left = new Node(2);
         root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
cout<<calcDiameter(root)<<"\n";}

//sum Rreplacement
/*replace the value of each node with the sum of all subtree nodes and itself*/
void sumReplace(Node* root){
    if(root == NULL){
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);
    if(root->left != NULL){
        root->data != root->left->data;
    }
    if(root->right != NULL){
        root->data += root->right->data;
    }
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(roo->left);
    preorder(root->right);
}

int main(){

    
    Node* root = new Node(1);
        root->left = new Node(2);
         root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //sumreplacement
    preorder(root);
    cout<<" \n";
    sumReplace(root);
    preorder(root);
    cout<<"\n";
    return 0;}

    //balanced Height tree
    /*For each node, the difference between the heights of the left subtree & right subtree<=1  */
    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh, rh) +1;
    }
    bool isBalanced(Node* root){
        if(isBalanced(root->left) == false){
            return false;
        }
        if(isBalanced(root->right)== false){
            return false;
        }
        int lh= height(root->left);
        int rh = height(root->right);
        if(abs(lh - rh) <= 1){
            return true;
        }
        else{
            return false;
        }
    }

    //right view of a binary tree
    void rightView(Node* root){
        if(root == NULL){
            return;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* curr = q.front();
                q.pop();

                if(i == n-1){
                    cout<<curr->data << " ";
                }
                if (curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
        }
    }
    int main(){

    
    Node* root = new Node(1);
        root->left = new Node(2);
         root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    rightView(root);
    return 0;}

//left view of a binary tree
#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        data= val;
        left= NULL;
        right = NULL;
    }
};

void leftView(Node* root){
    if(root== NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=1; i<=n; i++){
            Node* temp = q.front();
            q.pop();

            if(i== 1){
                cout<< temp->data<<" ";
            }
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}
int main(){

    
    Node* root = new Node(5);
        root->left = new Node(3);
         root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    leftView(root);
    cout<<endl;
    return;}