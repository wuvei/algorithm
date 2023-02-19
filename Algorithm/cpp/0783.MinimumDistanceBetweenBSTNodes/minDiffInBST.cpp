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
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *node = root;
        int prev = -100010, ans = INT_MAX;
        while (!st.empty() || node) {
            if (node) {
                st.push(node);
                node = node -> left;
            }
            else {
                TreeNode *temp = st.top();
                st.pop();
                ans = std::min(ans, temp->val - prev);
                prev = temp->val;
                node = temp->right;
            }
        }
        return ans;
    }
};