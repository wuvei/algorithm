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
    int x, xleft, xright;
    int childrenNum(TreeNode *root) {
        int l = 0, r = 0;
        if (root->left) l = childrenNum(root->left);
        if (root->right) r = childrenNum(root->right);
        if (root->val == x) {
            xleft = l;
            xright = r;
        }
        return l + r + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        this->x = x;
        int total = childrenNum(root);
        return (xright << 1) > total || (xleft << 1) > total || ((xleft + xright + 1) << 1) < total; 
    }
};