/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int f(Node* root){
        if(!root)return 0;
        
        int h1 = 1 + f(root->left);
        int h2 = 1 + f(root->right);
        return max(h1,h2);
    }
    int height(Node* root) {
        int mx = f(root);
        return mx-1;
        
    }
};