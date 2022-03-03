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
    TreeNode *helper(TreeNode *root) {
        if (!root) return root;
        root -> left = helper(root -> left);
        root -> right = helper(root -> right);
        if (dict.count(root -> val)) {
            if (root -> left) forest.push_back(root -> left);
            if (root -> right) forest.push_back(root -> right);
            delete root;
            root = nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        forest.clear();
        dict = unordered_set<int>(to_delete.begin(), to_delete.end());
        root = helper(root);
        if (root) forest.push_back(root);
        return forest;
    }

private:
    vector<TreeNode*> forest;
    unordered_set<int> dict;
};