//zig zag transversal
/* strategy
1. use 2 stacks- currentLevel & nextLevel
2. variable lefttoright
3. if lefttoright, push left child then right else, push right child then left*/
void zigzagTransversal(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    bool left toRight = true;
    currLevel.push(root);
    while(!currLevel.empty()){
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp){
            cout<<temp->data<<" ";
        
        if(leftToRght){
            if(temp->left){
                nextLevel.push(temp->left);
            }
            if(temp->right){
                nextLevel.push(temp->right);
            }
        }
        else{
            if(temp->right){
                nextLevel.push(temp->right);
            }
            if(temp->left){
                nextLevel.push(temp->left);
            }
        }
        }if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
        }
}
int main(){
    Node* root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right= new Node(10);
    zigzagTraversal(root);
    cout<<endl;
    return 0;
}

//are BST identical
/* For given root nodes of 2 binary search trees, print if the BSTs are identical or not.
Identical BSTs are structurally identical & have equal values for the nodes in the structure.*/

/*strategy
1. if both empty, return true
2. if both non-empty,
  a. check that the daya at nodes is equal
  b.check if left subtrees are same
  c. check if right subtrees are same
3. if(a,b,c) are true, return true else, return false  */
bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    else if(root1 == NULL || root2 == NULL){
        return false;
    }
    else{
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);
        if(cond1 && cond2 && cond3){
            return true;
        }
        return false;
    }
}
int main(){
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

     if(isIdentical(root, root)){
        cout<<"BSTs are identical" << endl;
     }else{
        cout<< "BSTs NOT Identical" << endl;
     }return 0;
}

//Largest BST in a binary tree
/*Return the size of the largest BST in a binary tree*/

/*for each node store the following info:
1. Min in subtree
2. Max in subtree
3. subtree size
4. size of largest BST
5. isBST*/

/* Recursively, traverse in a bootom up manner & find out the size of largest BST*/
#include <iostream>
using namespace std;

struct Info(){
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
}
Info largestBSTinBT(Node* root){
    if(root== NULL){
        return { 0, INT_MAX, INT_MIN, 0, true};
    }if(root->left == NULL && root->right == NULL){
        return {1, root->data, root->data, 1, true};
    }
    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max <root->data && rightInfo.min > root->data){
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(rightInfo.max, max(leftInfo.max, root->data));
        curr>min = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}
int main(){
    Node* root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);

    cout<<"Largest BST in BT : "<<largestBSTinBT(root).ans<<endl;
    return 0;
}

//restore BST
/* 2 nodes of a BST are swapped. our task is to restore(correct) the BST*/

/* 1. INorder of a BST is sorted
   2. elements in a sorted array are swapped
   3. maintain 3 pointers first,last and mid
   
   case 1 swapped elements are NOT adjacent to each other
   case 2 swapped elements are adjacent to each other*/

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}   

void calcPointers(Node* root, Node** first, Node** mid, Node** last, Node** prev){
    if(root== NULL){
        return;
    }
calcPointers(root->left, first,mid,last,prev);
if(*prev && root->data < (*prev)->data){
    if(!*first){
        *first = *prev;
        *mid = root;
    }
    else{
        *last = root;
    }
}    
*prev = root;
calcPointers(root->right, first, mid, last,prev);
}
void restoreBST(Node* root){
    Node* first, *mid, *last, *prev;
    first = NULL;
    mid= NULL;
    last= NULL;
    prev = NULL;
    calcPointers(root, &first, &mid, &last, &prev);
    if(first && last){
        swap(&(first->data), &(last->data));
    }else if(first & mid){
        swap(&(first->data), &(mid->data));
    }
}   
void inorder(Node* root){
    if(root== NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root-> right-> right = new Node(13);
    inorder(root);
    cout<<endl;
    restoreBST(root);
    inorder(root);
    cout<<endl;
    return 0;}