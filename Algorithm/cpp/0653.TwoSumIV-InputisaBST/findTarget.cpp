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
class InorderTreeIterator {
public:
    stack<TreeNode*> st;
    TreeNode* curr;
    bool isReversed;
    InorderTreeIterator(TreeNode* root, bool isReversed) {
        st.push(root);
        this->isReversed = isReversed;
        this->curr = root;
    }
    
    TreeNode* next() {
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = isReversed ? curr->right : curr->left;
            }
            curr = st.top();
            st.pop();
            TreeNode* currSave = curr;
            auto right = isReversed ? curr->left : curr->right;
            curr = right;
            return currSave;
        }
        return nullptr;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        InorderTreeIterator left(root, false);
        InorderTreeIterator right(root, true);
        
        TreeNode* l = left.next();
        TreeNode* r = right.next();
        while (l != r) {
            int sum = l->val + r->val;
            if (sum == k) return true;
            else if (sum < k) l = left.next();
            else r = right.next();
        }
        return false;
    }
};