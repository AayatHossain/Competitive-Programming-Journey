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

    bool f(node p, node q){
        if(!p && !q )return true;
        if(!p || !q)return false;
        
        if(p->val != q->val)return false;
        if(f(p->left,q->left) && f(p->right, q->right)){
            return true;
        }
       
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return f(p,q);
    }
};