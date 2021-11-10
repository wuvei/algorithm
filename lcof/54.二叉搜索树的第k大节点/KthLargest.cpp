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
    int kthLargest(TreeNode* root, int k) {
        vector<int> res;
        int idx = 0, temp;
        stack<TreeNode *> st;
        TreeNode* p = root, *node = root;
        while (p || !st.empty())
        {
            while (p)
            {
                st.push(p);
                p = p -> right;
            }
            node = st.top();
            st.pop();
            idx++;
            if (idx == k) break;
            p = node -> left;
        }
        return node -> val;
    }
};