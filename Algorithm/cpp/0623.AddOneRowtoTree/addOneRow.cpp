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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode *new_node = new TreeNode(val);
            new_node->left = root;
            return new_node;
        }
        queue<TreeNode*> q;
        q.push(root);
        for (int i = 1; i < depth - 1; ++i) {
            int len = q.size();
            for (int j = 0; j < len; ++j) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            TreeNode *l_new_node = new TreeNode(val);
            l_new_node->left = node->left;
            node->left = l_new_node;
            TreeNode *r_new_node = new TreeNode(val);
            r_new_node->right = node->right;
            node->right = r_new_node;
        }
        return root;
    }
};