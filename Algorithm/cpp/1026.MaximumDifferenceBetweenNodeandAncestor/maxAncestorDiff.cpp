class Solution {
public:
    void dfs(TreeNode* node, int up, int low) {
        if (!node) return;
        ans = std::max({ans, std::abs(node->val - up), std::abs(node->val - low)});
        up = std::max(node->val, up);
        low = std::min(node->val, low);
        dfs(node->left, up, low);
        dfs(node->right, up, low);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
private:
    int ans = 0;
};