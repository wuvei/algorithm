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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool flag = true;
        TreeNode *node;
        while (!dq.empty()) {
            int len = dq.size();
            vector<int> t;
            t.reserve(len);
            while (len--) {
                if (flag) {
                    node = dq.front();
                    dq.pop_front();
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                }
                else {
                    node = dq.back();
                    dq.pop_back();
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
                t.push_back(node->val);
            }
            flag = !flag;
            ans.push_back(std::move(t));
        }
        return ans;
    }
};