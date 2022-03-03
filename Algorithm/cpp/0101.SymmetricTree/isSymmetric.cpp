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
    bool compare(TreeNode *l, TreeNode *r) {
        if (!l || !r) return !l && !r;
        return (l -> val == r -> val) && compare(l -> left, r -> right) && compare(l -> right, r -> left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return compare(root -> left, root -> right);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue <TreeNode*> q;
        q.push(root -> left); q.push(root -> right);
        while (!q.empty()) {
            TreeNode* u = q.front(); q.pop();
            TreeNode* v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }
};