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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root -> left && !root -> right) return 1;
        return std::max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }

    int maxDepth2(TreeNode* root) {
        if (!root) return 0;
        if (!root -> left && !root -> right) return 1;
        queue<TreeNode *> q;
        int depth = 0;
        q.push(root);
        while (!q.empty()) {
            int curSize = q.size();
            for (int i = 0; i < curSize; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            depth++;
        }
        return depth;
    }
};