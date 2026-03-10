//string serialization plus kmp. O(n+m) time and space approach


class Solution {
private:
    using node = TreeNode*;
    void pre(node r, string &s){
        if(!r){
            s+=" N";
            return;
        }

        s+= " " + to_string(r->val);
        pre(r->left,s);
        pre(r->right,s);

        return;
    }

    bool kmp(string &s, string &t){
        
        vector<int> lps(t.size(),0);
        makelps(t,lps);
        int n = s.size();
        int m = t.size();

        int i = 0,j = 0;
        while(i < n){
            
            if(s[i]==t[j]){
                i++; j++;
                if(j==m){
                    return true;
                }
            }else{
                if(j!=0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return false;
    }

    void makelps(string t, vector<int> &lps){
        int length = 0, i= 1;
        int m = lps.size();
        while(i < m){
            if(t[i]==t[length]){
                length++;
                lps[i] = length;
                i++;
            }else{
                if(length != 0){
                    length = lps[length - 1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }


public:
    bool isSubtree(TreeNode* r, TreeNode* sr) {
        string pr;
        pre(r,pr);

        string psr;
        pre(sr,psr);
        
        bool f = kmp(pr,psr);
        return f;
    }
};