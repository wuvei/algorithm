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
    vector<int> sums;
    int dfs(TreeNode *root) {
        int left = 0, right = 0;
        if (root->left) left = dfs(root->left);
        if (root->right) right = dfs(root->right);
        int tot = left + right + root->val;
        sums.push_back(tot);
        return tot;
    }
    int maxProduct(TreeNode* root) {
        int tot = dfs(root);
        sums.pop_back();
        long long ans = 0;
        for (int e: sums) {
            ans = std::max(ans, 1LL * e * (tot - e));
        }
        return static_cast<int>(ans % static_cast<long long>(1e9 + 7));
    }
};