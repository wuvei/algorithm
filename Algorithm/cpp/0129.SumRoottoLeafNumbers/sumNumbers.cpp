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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root, root->val});
        while(!s.empty()) {
            auto [node, cur] = s.top();
            s.pop();
            if (!node->left && !node->right) {
                ans += cur;
            } else {
                int t = cur * 10;
                if (node->right) s.push({node->right, t + node->right->val});
                if (node->left) s.push({node->left, t + node->left->val});
            }
        }
        return ans;
    }
};