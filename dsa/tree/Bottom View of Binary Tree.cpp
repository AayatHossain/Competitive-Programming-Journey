/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    map<int,int> m;
    vector<int> a;
    void f(Node* root){
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node* n = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            m[hd] = n->data;
            
            if(n->left)q.push({n->left, hd-1});
            if(n->right)q.push({n->right, hd+1});
        }
        
        
         for(auto x: m){
            a.push_back(x.second);
        }
    }
    
    vector<int> bottomView(Node *root) {
        // code here
        f(root);
        return a;
        
    }
};