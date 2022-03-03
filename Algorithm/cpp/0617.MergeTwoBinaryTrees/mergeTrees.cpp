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
    void traversal(TreeNode* r1, TreeNode* r2, TreeNode* root) {
        root -> val = (r1 ? r1 -> val: 0) + (r2 ? r2 -> val: 0);
        if ((r1 && r1 -> left) || (r2 && r2 -> left)) {
            root -> left = new TreeNode();
            traversal(r1? r1 -> left: r1, r2? r2 -> left: r2, root -> left);
        }
        if ((r1 && r1 -> right) || (r2 && r2 -> right)) {
            root -> right = new TreeNode();
            traversal(r1? r1 -> right: r1, r2? r2 -> right: r2, root -> right);
        }
        
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        TreeNode *root = new TreeNode();
        traversal(root1, root2, root);
        return root;
    }
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        auto merged = new TreeNode(t1->val + t2->val);
        merged->left = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/merge-two-binary-trees/solution/he-bing-er-cha-shu-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return NULL;
        if(!r1) return r2;
        if(!r2) return r1;
        queue<pair<TreeNode*,TreeNode*> > q;
        q.push({r1,r2});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            temp.first->val += temp.second->val;
            
            if(temp.first -> left && temp.second -> left)
                q.push({temp.first->left, temp.second->left});
            else if (temp.second->left)
                temp.first -> left = temp.second->left;
            
            if(temp.first -> right && temp.second -> right)
                q.push({temp.first->right, temp.second->right});
            else if (temp.second->right)
                temp.first -> right = temp.second -> right;         
        }
        return r1;
    }
};