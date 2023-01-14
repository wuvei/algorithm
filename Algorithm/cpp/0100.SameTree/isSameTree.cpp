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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        stack<TreeNode*> st1, st2;
        st1.push(p);
        st2.push(q);
        while (!st1.empty() && !st2.empty()) {
            TreeNode *n1 = st1.top(), *n2 = st2.top();
            st1.pop();
            st2.pop();
            if (n1 && n2 && n1->val == n2-> val) {
                st1.push(n1->right);
                st1.push(n1->left);
                st2.push(n2->right);
                st2.push(n2->left);
            }
            else if (n1 || n2)
                return false;
        }
        return true;
    }
};