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
private:
    int maxSum = INT_MIN;
public:
    int maxGain(TreeNode* root) {
        if (!root) return 0;
        int leftGain = std::max(maxGain(root -> left), 0);
        int rightGain = std::max(maxGain(root -> right), 0);
        int pathSum = leftGain + rightGain + root -> val;
        if (pathSum > maxSum) maxSum = pathSum;
        return root -> val + std::max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};