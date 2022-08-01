// Similar to Morris
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                auto next = curr->left;
                auto predecessor = next;
                while (predecessor->right != nullptr)
                    predecessor = predecessor->right;
                
                predecessor->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solution/er-cha-shu-zhan-kai-wei-lian-biao-by-leetcode-solu/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


// reverse post Order with a prev node
class Solution {
private:
    TreeNode* prev = nullptr;
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};