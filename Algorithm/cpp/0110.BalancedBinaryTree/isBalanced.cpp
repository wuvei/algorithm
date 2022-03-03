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
    int getDepth(TreeNode *root) {
        if (!root) return 0;
        int left = getDepth(root -> left);
        if (left == -1) return -1;
        int right = getDepth(root -> right);
        if (right == -1) return -1;
        if (std::abs(left - right) <= 1) return std::max(left, right) + 1;
        return -1;
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root) != -1;
    }
};