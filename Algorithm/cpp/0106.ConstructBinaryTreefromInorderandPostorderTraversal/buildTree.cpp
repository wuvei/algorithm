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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        std::function<TreeNode*(pair<int, int>, pair<int, int>)> build = [&](pair<int, int> in, pair<int, int> post) -> TreeNode* {
            if (in.first > in.second) return nullptr;
            int val = postorder[post.second];
            TreeNode *root = new TreeNode(val);
            if (in.first == in.second) return root;
            int idx = in.first;
            for (; inorder[idx] != val; ++idx);
            int left = idx - in.first;
            root->left = build({in.first, idx - 1}, {post.first, post.first + left - 1});
            root->right = build({idx + 1, in.second}, {post.first + left, post.second - 1});
            return root;
        };
        return build({0, inorder.size() - 1}, {0, postorder.size() - 1});
    }
};