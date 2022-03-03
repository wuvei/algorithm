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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        convertBST(root -> right);
        sum += root -> val;
        root -> val = sum;
        convertBST(root -> left);
        return root;
    }
private:
    int sum = 0;
};

class Solution {
public: 
    TreeNode* convertBST(TreeNode *root){
      stack<TreeNode*> stack;
        int sum = 0;
        TreeNode *ans = root;
        while(!stack.empty() || root){
            while (root){
                stack.push(root);
                root = root -> right;
            }
            root = stack.top();
            stack.pop();
            sum += root -> val;
            root -> val = sum;
            root = root -> left;
        }
        return ans;
    }
};