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
    int sum = 0, target = 0;
    bool dfs(TreeNode* root) {
        if (!root->left && !root->right) {
            return sum + root->val == target;
        }
        sum += root->val;
        bool ifleft = root->left ? dfs(root->left) : false;
        if (ifleft) {
            return true;
        }
        bool ifright = root->right ? dfs(root->right) : false;
        if (ifright) {
            return true;
        }
        sum -= root->val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        target = targetSum;
        sum = 0;
        return dfs(root);
    }
};