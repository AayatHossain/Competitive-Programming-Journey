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
    Node* init;
    void f(Node* root, vector<int> &c){
        if(!root)return;
        if(!(root->left) && !(root->right) && root!=init){
            c.push_back(root->data);
            return;
        }
        f(root->left,c);
        f(root->right,c);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> a;
        vector<int> b;
        vector<int> c;
        init = root;
        a.push_back(root->data);
        
        
        
        Node* curr = root->left;
        while(curr){
            if(!(curr->left) && !(curr->right)){
                break;
            }
            
            a.push_back(curr->data);
            if(curr->left){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        

        curr = root->right;
        while(curr){
            if(!(curr->left) && !(curr->right)){
                break;
            }
        
        
            b.push_back(curr->data);
            if(curr->right){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
            
        }
        reverse(b.begin(),b.end());
        
        f(root,c);
       
        vector<int> res;
        for(int i = 0; i < a.size(); i++){
            res.push_back(a[i]);
        }
        for(int i = 0; i < c.size(); i++){
            res.push_back(c[i]);
        }
         for(int i = 0; i < b.size(); i++){
            res.push_back(b[i]);
        }
        return res;
        
    }
};