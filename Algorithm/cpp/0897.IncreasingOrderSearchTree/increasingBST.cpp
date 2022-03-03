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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode dummy(0);
        TreeNode *node = &dummy;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root -> left;
            }
            else {
                root = st.top();
                st.pop();
                node -> right = new TreeNode(root -> val);
                node = node -> right;
                root = root -> right;
            }
        }
        return dummy.right;
    }
};