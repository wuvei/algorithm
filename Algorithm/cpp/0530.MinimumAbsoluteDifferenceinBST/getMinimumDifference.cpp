class Solution {
public:
    
    int getMinimumDifference(TreeNode* root) {
        if (root->left)
            getMinimumDifference(root -> left);
        
        if (pre >= 0) 
            diff = min(diff, root -> val - pre);
        pre = root->val;
        
        if (root->right) 
            getMinimumDifference(root -> right);
        return diff;
    }
private:
    int pre = -1, diff = INT_MAX;
};
