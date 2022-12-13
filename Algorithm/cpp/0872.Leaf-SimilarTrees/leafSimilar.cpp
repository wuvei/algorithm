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
    vector<int> getSeq(TreeNode *root) {
        vector<int> ans;
        function<void(TreeNode*)> f = [&](TreeNode *node) {
            if (!node->left && !node->right) {
                ans.push_back(node->val);
            }
            else {
                if (node->left) f(node->left);
                if (node->right) f(node->right);
            }
        };
        f(root);
        return std::move(ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return getSeq(root1) == getSeq(root2);
    }
};