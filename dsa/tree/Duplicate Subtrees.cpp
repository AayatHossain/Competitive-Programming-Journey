class Solution {
  public:
    int id = 1;
    vector<Node*> a;
    map<tuple<int,int,int>,int> m1;
    map<int, int> m2;
    int f(Node* r){
        if(!r)return 0;
        int nl = f(r->left);
        int nr = f(r->right);
        
        tuple<int,int,int> t = {r->data,nl,nr};
        
        if(m1.find(t) == m1.end()){
            id++;
            m1[t]=id;
        }
        int curr = m1[t];
        
        m2[curr]++;
        if(m2[curr] == 2){
            a.push_back(r);
        }
        return curr;
    }
    vector<Node*> printAllDups(Node* root) {
        // Code here
        int v = f(root);
        return a;
    }
};