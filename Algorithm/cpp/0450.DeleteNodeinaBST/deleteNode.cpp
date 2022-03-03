class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (!root) return nullptr;
        if (key > root->val)    root->right = deleteNode(root->right, key);
        else if (key < root->val)    root->left = deleteNode(root->left, key);
        else {
            if (!root->left)   return root->right;
            if (!root->right)  return root->left;
            TreeNode* node = root->right; // 情况3，欲删除节点左右子都有 
            while (node->left)          // 寻找欲删除节点右子树的最左节点
                node = node->left;
            node->left = root->left;    // 将欲删除节点的左子树成为其右子树的最左节点的左子树
            root = root->right;         // 欲删除节点的右子顶替其位置，节点被删除
        }
        return root;    
    }
};