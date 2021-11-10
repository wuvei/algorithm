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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        bool flag = false;
        TreeNode *node = root;
        int p_val = std::min(p -> val, q -> val), q_val = std::max(p -> val, q -> val), v;

        while(!flag) {
            v = node -> val;
            if (v == p_val || v == q_val || (v > p_val && v < q_val)) flag = true;
            else if (v > q_val) node = node -> left;
            else node = node -> right;
        }
        return node;
    }
};