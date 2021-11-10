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
    int getGain(TreeNode* root) {
        if (!root) return 0;
        int leftGain = getGain(root -> left);
        int rightGain = getGain(root -> right);
        diameter = std::max(diameter, leftGain + rightGain + 1);
        return std::max(leftGain, rightGain) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        getGain(root);
        return diameter - 1;
    }
private:
    int diameter;
};