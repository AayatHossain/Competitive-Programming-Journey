/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    bool f = 1;
    int c = -1;
    void dfs(Node* root, int d){
        if(!root || !f)return;
        if(root->left==nullptr && root->right==nullptr){
            if(c!= -1 && c!=d){
                f = 0;
                return;
            }else{
                c = d;
                return;
            }
        }
        dfs(root->left,d+1);
        dfs(root->right,d+1);
        
    }
    
    /*You are required to complete this method*/
    bool check(Node *root) {
        // Your code here
        dfs(root,1);
        if(f)return true;
        return false;
        
    }
};