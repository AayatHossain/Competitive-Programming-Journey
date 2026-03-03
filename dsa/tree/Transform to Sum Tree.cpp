/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    void f(Node* r){
        if(!r){
            
            return;
        }
        if(r->left==nullptr && r->right==nullptr){
            r->data = 0;
            return;
        }
        int s = 0;
        if(r->left)s+=r->left->data;
        if(r->right)s+=r->right->data;
        
        f(r->left);
        f(r->right);
     
        if(r->left)s+=r->left->data;
        if(r->right)s+=r->right->data;
        
        r->data = s;
        return;
        
    }
    
    void toSumTree(Node *node) {
        // Your code here
        f(node);
        return;
        
    }
};