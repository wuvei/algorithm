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
    enum stat {COV, NOCOV, MONI, ERROR};
    stat dfs(TreeNode *root) {
        if (!root) return COV;
        stat n1 = dfs(root -> left), n2 = dfs(root -> right);
        
        if (n1 == COV && n2 == COV) return NOCOV;
        
        if (n1 == NOCOV || n2 == NOCOV) {
            ++monitors;
            return MONI;
        }
        if (n1 == MONI || n2 == MONI) return COV;
        
        return ERROR;
    }
    int minCameraCover(TreeNode* root) {
        monitors = 0;
        if (dfs(root) == NOCOV) ++monitors;
        return monitors;
    }
private:
    int monitors;
};