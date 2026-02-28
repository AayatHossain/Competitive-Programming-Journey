/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
class Solution {
  public:
  
    void f(Node *root, vector<int> &ans){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* n = q.front();
            q.pop();
            ans.push_back(n->data);
            if(n->right != nullptr)q.push(n->right);
            if(n->left != nullptr) q.push(n->left);
            
        }
        return;
    }
  
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        vector<int> ans;
        f(root,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};