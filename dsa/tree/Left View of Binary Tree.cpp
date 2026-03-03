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
    void f(Node *r, vector<int> &a){
        queue<Node*> q;
        q.push(r);
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                Node *n = q.front();
                q.pop();
                if(i==0){
                    a.push_back(n->data);
                }
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }
            
        }
        return;
    }
    vector<int> leftView(Node *root) {
        vector<int> a;
        f(root,a);
        
        return a;
        
    }
};