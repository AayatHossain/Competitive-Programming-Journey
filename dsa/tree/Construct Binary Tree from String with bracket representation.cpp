// User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/

Node* f(string &s, int &i, int n){
    if(i >= n || s[i]==')')return nullptr;
    
    Node* r = new Node(0);
    
    if(s[i]!=')' && s[i]!='('){
        int v = 0;
        while(i < n && (s[i]!=')' && s[i]!='(')){
            int v1 = s[i] - '0';
            v = v*10 + v1;
            i++;
        }
        r->data = v;
    }
    if(i < n && s[i]=='('){
        i++;
        r->left = f(s,i,n);
        i++;
    }
    if(i < n && s[i]=='('){
        i++;
        r->right = f(s,i,n);
        i++;
    }
    return r;
}

class Solution {
  public:
    // function to construct tree from string
    Node *treeFromString(string str) {
        int i = 0;
        Node* ans = f(str,i,str.size());
        return ans;
        
    }
};