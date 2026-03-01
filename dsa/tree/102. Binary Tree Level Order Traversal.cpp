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
    void f(TreeNode* root, vector<vector<int>> &ans){
        if(!root)return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> b;
            int s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode* n = q.front();
                q.pop();
                b.push_back(n->val);
                if(n->left != nullptr){
                    q.push(n->left);
                }
                if(n->right != nullptr){
                    q.push(n->right);
                }
            }
            ans.push_back(b);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> a;
        f(root,a);
        return a;
    }
};