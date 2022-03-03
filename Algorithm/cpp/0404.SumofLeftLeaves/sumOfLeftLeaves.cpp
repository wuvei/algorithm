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
    int helper (TreeNode *root, bool isLeft) {
        if (!root -> left && !root -> right) return isLeft? root -> val: 0;
        int temp = 0;
        if (root -> left) temp += helper(root -> left, true);
        if (root -> right) temp += helper(root -> right, false);
        return temp;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};