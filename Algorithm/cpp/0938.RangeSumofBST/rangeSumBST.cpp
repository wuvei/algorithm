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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        std::function<void(TreeNode*)> f = [&](TreeNode *node) {
            if (node->val >= low && node->val <= high) {
                ans += node->val;
                if (node->left) f(node->left);
                if (node->right) f(node->right);
            }
            else if (node->val < low) {
                if (node->right) f(node->right);
            }
            else if (node->left) f(node->left);
        };
        f(root);
        return ans;
    }
};