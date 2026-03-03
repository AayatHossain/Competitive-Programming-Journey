/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int f1 = 1;
    int f(Node* r){
        if(!f1)return -1;
        if(!r)return 0;
        int left = 1 + f(r->left);
        int right = 1 + f(r->right);
        if(abs(right - left) > 1){
            f1 = 0;
            return -1;
        }
        return max(left, right);
    }
    bool isBalanced(Node* root) {
        // code here
        int c = f(root);
        if(!f1){
            return false;
        }else{
            return true;
        }
    }
};