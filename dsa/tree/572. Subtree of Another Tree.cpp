/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool f1(TreeNode* r1, TreeNode* r2) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({r2, r1});
        while (!q.empty()) {
            pair<TreeNode*, TreeNode*> t = q.front();
            TreeNode* n = t.first;
            TreeNode* n2 = t.second;
            q.pop();
            if (!n && !n2)
                continue;
            if (!n || !n2)
                return false;
            if (n->val != n2->val)
                return false;

            q.push({n->left, n2->left});
            q.push({n->right, n2->right});
        }
        return true;
    }
    bool f(TreeNode* r1, TreeNode* r2) {
        queue<TreeNode*> q;
        q.push(r1);
        while (!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            if (n->val == r2->val) {
                bool ok = f1(n, r2);
                if (ok)
                    return true;
            }
            if (n->left != nullptr)
                q.push(n->left);
            if (n->right != nullptr)
                q.push(n->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ok = f(root, subRoot);
        return ok;
    }
};