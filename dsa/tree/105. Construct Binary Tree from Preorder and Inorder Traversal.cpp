/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    using node = TreeNode*;
    map<int,int> m;

    node f(vector<int>& po, vector<int>& io, int l, int r, int &pi){
        if(l > r)return nullptr;
        int rootval = po[pi];
        pi++;

        node root = new TreeNode(rootval);
        int rootindex = m[rootval];

        root->left = f(po,io,l,rootindex-1,pi);
        root->right = f(po,io,rootindex+1,r,pi);

        return root;
    }

    TreeNode* buildTree(vector<int>& po, vector<int>& io) {
        int n = po.size();
        int preindex = 0;
        for(int i = 0; i < n; i++){
            m[io[i]] = i;
        }
        node res = f(po,io,0,n-1,preindex);
        return res;

    }
};