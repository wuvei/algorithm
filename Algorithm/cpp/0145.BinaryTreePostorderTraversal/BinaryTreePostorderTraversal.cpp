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
// https://shubo.io/iterative-binary-tree-traversal/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            if (!(node -> left) && !(node -> right)) {
                res.push_back(node -> val);
                s.pop();
            }
            if (node -> right) {
                s.push(node -> right);
                node -> right = nullptr;
            }
            if (node -> left) {
                s.push(node -> left);
                node -> left = nullptr;
            }
        }
        return res;
    }
};