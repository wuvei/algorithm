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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int root_idx, int start, int end) {
    /*
        root_idx: root node's index in preorder.
        start: subtree's start pos in inorder.
        end: subtree's end pos in inorder.
    */
        if (start > end) return nullptr;
        TreeNode *root = new TreeNode(preorder[root_idx]);
        if (start == end) return root;
        vector< int >::iterator iter = std::find(inorder.begin() + start, inorder.begin() + end + 1, preorder[root_idx]);
        int i = iter - inorder.begin();

        root -> left = build(preorder, inorder, root_idx + 1, start, i - 1);
        root -> right = build(preorder, inorder, root_idx + 1 + i - start, i + 1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};