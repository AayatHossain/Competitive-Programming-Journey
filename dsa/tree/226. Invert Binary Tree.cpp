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
    void f(TreeNode* r){
        if(!r)return;
        f(r->left);
        f(r->right);
        TreeNode* tmp = r->left;
        r->left = r->right;
        r->right = tmp;
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        f(root);
        return root;
    }
};