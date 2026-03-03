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
                if(i==s-1){
                    a.push_back(n->data);
                }
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }
            
        }
        return;
    }
    vector<int> rightView(Node *root) {
        vector<int> a;
        f(root,a);
        
        return a;
        
    }

};


IMPROVED DEQUE Solution
/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
   
    void f(Node *r, vector<int> &a){
        deque<Node*> q;
        q.push_back(r);
        int c = 1;
        while(!q.empty()){
            int s = q.size();
            if(c&1){
                for(int i = 0; i < s; i++){
                    Node* n = q.front();
                    q.pop_front();
                    a.push_back(n->data);
                    if(n->left)q.push_back(n->left);
                    if(n->right)q.push_back(n->right);
                }
                
            }else{
                for(int i = 0; i < s; i++){
                    Node* n = q.back();
                    q.pop_back();
                    a.push_back(n->data);
                    if(n->right)q.push_front(n->right);
                    if(n->left)q.push_front(n->left);
                }
                
            }
            c++;
        }
        return;
    }
  
    vector<int> zigZagTraversal(Node* root) {
        vector<int> a;
        f(root,a);
        return a;
        
    }
};
