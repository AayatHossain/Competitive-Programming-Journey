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
   
    int dfs(TreeNode* root, int d, int mx){
        if(root==nullptr){
            return d-1;
        }

        int m1 = dfs(root->left, d+1,mx);
        int m2 = dfs(root->right, d+1,mx);
        return max(m1,m2);

    }

    int maxDepth(TreeNode* root) {
       
        return dfs(root,1,-1);
    }
};