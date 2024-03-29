//what is catalan number
/* Catalan numbers are a sequence of natural numbers that occur in various counting problems, often involving
recursively defined objects*/                   //c0= 1, c1= 1, c2= 2, c3= 5, c4= 14
#include<iostream>
using namespace std;
int catalan(int n){
    if(n <= 1){
        return 1;
    }
    int res = 0;
    for(int i=0; i<=n-1; i++){
        res += catalan(i) * catalan(n-i-1);
    }
    return res;
}
int main(){
    for(int i=0; i<10; i++){
        cout<< catalan(i) << " ";
    }
    cout << endl;
    return 0;
}
/* applications of catalan number
1.Possible BSTs
2. paranthesis/ bracket combinations
3. possible forests
4. ways of triangulations
5. Possible paths in matrix
6. Dividing a circle using N chords
7. Dyck words of given length & much more*/

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
vector<Node*> constructTrees(int start, int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start; i<=end; i++){
        vector<Node*> leftSubtrees = constructTrees(start, i-1);
        vector<Node*> rightSubtrees = constructTrees(i+1, endl);
        for(int j=0; j<leftSubtrees.size(); j++){
            Node* left = leftSubtrees[j];
            for(int k=0; k<rightSubtree.size(); k++){
                Node* right = rightSubtrees[k];
                Node* node = new Node(i);
                node->left= left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }return trees;
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    vector<Node*> totalTrees = constructTrees(1,3);
    for(int i=0; i<totalTrees.size(); i++){
        cout<< (i+1) <<" : ";
        preorder(totalTrees[i]);
        cout<<endl;
    }return 0;
}