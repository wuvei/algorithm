/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = getHeight(root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(root -> right);
        if (rightHeight == -1 || abs(leftHeight - rightHeight) > 1) return -1;
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (getHeight(root) != -1) return true;
        else return false;
    }
};