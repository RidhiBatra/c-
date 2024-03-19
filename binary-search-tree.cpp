/* rule 1_   the left subtree of a node contains only nodes with keys lesser than the node's key
   ruke 2_ the right subtree of a node contains only nodes with keys greater than the node's key
   rule 3_ the left and right subtree each must also be a binary search tree. there must be no duplicate nodes*/
   #include<iostream>
using namespace std;
struct node{
    int data;
    Node *left, *right;

    Node(int val){
        data= val;
        left = NULL;
        right = NULL;
    }
};
Node* insertBST(Node *root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left, val);
    }else{
        root->right = insertBST(root->right, val);
    }return root;`                                              /*binary tree: timecomplexity O(n) */
}                                                               /*binary search tree: time complexity O(logn) */
void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    inorder(root);
    cout<<endl;
    return 0;
}

//search in BST
Node* searchInBST(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data >key){
        return searchInBST(root->left,key);
    }return searchInBST(root->right, key);
}
int main(){
    root->left->left = new Node(1);
     root->left->right = new Node(3);
      root->right->right = new Node(6);
      if(searchInBST(root, 5) == NULL){
        cout << "key doesnt exist";
      }else{
        cout<<"key exists";
      }return 0;
}
//delete in a BST
/*case 1   node is a leaf
case 2  node has one child
case 3  node has two children*/
Node* inOrderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left!=NULL){
        curr= curr->left;
    }return curr;
}
Node* deleteInBST(Node* root, int key){
    if(key < root->data){
        root->left = deleteInBST(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteInBST(root->right, key);
    }else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;        }
    //case3
    Node* temp = inOrderSucc(root->right);
    root->data = temp->data;
    root->right = deleteInBST(root->right, temp->key);
    }
    return root;
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node *root = new Node(4);
    root->left = new node(2);
    root->right = new Node (5);
    root->left->left= new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    inorder(root);
    root = deleteInBST(root, 5);inorder(root);
    cout<< endl;
    return 0;
}

//build BST from preorder
Node* constructBST(int preorder[], int* preorderIdx, int key, int min, int max, int n){
    if(*preorderIdx >= n){
        return NULL;
    }
    Node* root = NULL;
    if(key > min && key <max){
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;
        if(*preorderIdx < n){
            root->left = constructBST(preorder, preorderIdx, preorder[*preordeIdx], min, key, n);
        }
        if(*preorderIdx <n)
        {
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }    }
        return root;
}
void printPreorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<< root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
int main(){
    int preorder[] = {10,2,1,13,11};
    int n = 5;
    int preorderIdx = 0;
    constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    printPreorder(root);
    return 0;
}

//check for BST
/*Approach 1    node>leftchild
                node<rightchild
  approach 2    Max of left subtree(maxL)       node> maxL
                min of right subtree(minR)      node< minR                
  approach3     min allowed                     min allowed < node             left(min,node)
                max allowed                     max allowed > node              right(node, max)*/
bool isBST(Node* root, Node* min, Node* max = NULL){
    if(root == NULL){
        return true;
    }
    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL & root->data >= max->data){
        return false;
    }
    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);
    return leftValid and rightValid;
}                
int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    if(isBST(root1, NULL, NULL)){
        cout<<" valid BST" << endl;
    }else{ cout << "invalid BST" << endl;}
    return 0;
}

//Sorted array to balanced BST
/* strategy-> binary search like
            1. Make middle element the root
            2. Recursively, do the same for subtrees
                    a. start to mid -1 for left subtree
                    b. mid +1 to end for right subtree*/
Node* sortedArrayToBST(int arr[], int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);
    return root;
}
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    Node* root = sortedArrayToBST(arr, 0, 4);
    preorderPrint(root);
    cout<<endl;
    return 0;
}