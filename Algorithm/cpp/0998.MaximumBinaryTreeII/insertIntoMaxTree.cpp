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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *insert = new TreeNode(val);
        if (root->val < val) {
            insert->left = root;
            return insert;
        }
        TreeNode *prev = root, *node = root->right;
        while (node && node->val > val) {
            prev = node;
            node = node->right;
        }
        prev->right = insert;
        insert->left = node;
        return root;
    }
};