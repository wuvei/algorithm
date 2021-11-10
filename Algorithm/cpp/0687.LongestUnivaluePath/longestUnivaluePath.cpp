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
    int gain(TreeNode* root) {
        if (!root) return 0;
        int l = gain(root -> left), r = gain(root -> right);
        if (!(root -> left) || root -> val != root -> left -> val) l = 0;
        if (!(root -> right) || root -> val != root -> right -> val) r = 0;
        nodes = std::max(l + r + 1, nodes);
        return std::max(l, r) + 1;
    }
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        nodes = 0;
        gain(root);
        return nodes - 1;
    }
private:
    int nodes;
};