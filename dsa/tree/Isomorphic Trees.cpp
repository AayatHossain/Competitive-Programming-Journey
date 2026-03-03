/*Complete the function below
Node is as follows:
struct Node {
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
    
    bool f(Node *r1, Node *r2){
       if(!r1 && !r2)return true;
       if(!r1 || !r2)return false;
       
       
       if((r1->data != r2->data))return false;
       if(f(r1->left,r2->left) && f(r1->right,r2->right)){
           return true;
       }
       if(f(r1->left,r2->right) && f(r1->right,r2->left)){
           return true;
       }
       return false;
    }
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1, Node *root2) {
        // add code here.
        return f(root1,root2);
    }
};