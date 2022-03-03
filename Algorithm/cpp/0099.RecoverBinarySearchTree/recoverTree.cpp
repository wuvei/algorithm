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
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root -> left);
        if (pre && pre -> val > root -> val) {
            if (!x) x = pre;
            y = root;
        }
        pre = root;
        inorder(root -> right);
    }
    void recoverTree(TreeNode* root) {
        x = y = pre = nullptr;
        inorder(root);
        swap(x->val, y->val);
    }
    
private:
    TreeNode *x, *y, *pre;
};


// Morris
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *mostRight = nullptr, *x = nullptr, *y = nullptr, *pre = nullptr;
        while (root) {
            mostRight = root -> left;
            if (mostRight) {
                while (mostRight -> right && mostRight -> right != root)
                    mostRight = mostRight -> right;
                if (!mostRight -> right) {
                    mostRight -> right = root;
                    root = root -> left;
                }
                else {
                    if (pre && pre -> val > root -> val) {
                        if (!x) x = pre;
                        y = root;
                    }
                    pre = root;
                    mostRight -> right = nullptr;
                    root = root -> right;
                }
            }
            else {
                if (pre && pre -> val > root -> val) {
                    if (!x) x = pre;
                    y = root;
                }
                pre = root;
                root = root -> right;
            }
        }
        swap(x->val, y->val);
    }
    
};