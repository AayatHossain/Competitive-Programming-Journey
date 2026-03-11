/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    int f1 = 0;
    set<string> st;
    string f(Node* r){
        if(!r)return "N";
        if(!r->left && !r->right){
            return to_string(r->data);
        }
        string s;
        string s1 = to_string(r->data);
        string s2 = f(r->left);
        string s3 = f(r->right);
        
        if(s2 != "" && s3 != ""){
            s = s1+" "+s2+" "+s3;
            if(st.find(s) != st.end()){
                f1 = 1;
            }else{
                st.insert(s);
            }
            return "";
        }else{
            return "";
        }
        
        
    }
    
    
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
       string t = f(root);
       if(f1)return true;
       else return false;
    }
};