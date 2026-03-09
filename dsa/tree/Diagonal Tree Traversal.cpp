/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        vector<int> ans;
        queue<Node*>q;
        q.push(root);
        Node* curr;
        while(!q.empty()){
            Node* n = q.front();
            q.pop();
           
            curr = n;
            while(curr){
                ans.push_back(curr->data);
                if(curr->left){
                    q.push(curr->left);
                    
                }
                curr = curr->right;
                
            }
        }
        return ans;
    }
};