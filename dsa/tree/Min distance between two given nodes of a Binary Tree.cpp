/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    Node* lcaf(Node* r, int a, int b){
        if(!r)return nullptr;
        if(r->data==a || r->data == b){
            return r;
        }
        Node* lnode = lcaf(r->left, a,b);
        Node* rnode = lcaf(r->right, a,b);
        
        if(lnode && rnode)return r;
        
        if(lnode)return lnode;
        return rnode;
    }
    
    int dfs(Node* r, int a, int d){
        if(!r)return -1;
        if(r->data==a)return d;
        
        int ld = dfs(r->left, a, d+1);
        int rd = dfs(r->right, a, d+1);
        
        if(ld != -1)return ld;
        if(rd != -1)return rd;
        return -1;
        
    }
  
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lca = lcaf(root,  a,  b);
        int d1 = dfs(lca, a, 0);
        int d2 = dfs(lca, b, 0);
        
        return d1 + d2;
        
    }
};