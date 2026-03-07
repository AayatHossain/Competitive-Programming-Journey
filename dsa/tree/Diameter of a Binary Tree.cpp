/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int mx = INT_MIN;
    int f(Node* root){
        if(!root)return 0;
        
        int h1 = f(root->left)+1;
        int h2 = f(root->right)+1;
        mx = max(h1+h2-2,mx);
        
        return max(h1,h2);
        
    }
    int diameter(Node* root) {
        int v = f(root);
        return mx;
        
    }
};