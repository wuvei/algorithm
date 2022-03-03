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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!t) return true;
        else if(!s) return false;
        return (helper(s, t) || isSubtree(s -> left, t) || isSubtree(s -> right, t));
    }
    
    bool helper(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(s->val != t->val) return false;
        return (helper(s -> left, t -> left) && helper(s -> right, t -> right));
    }
};

constexpr uint64_t lb = 2333, rb = 97755331, mb = 23333;
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        function<int(TreeNode*)> trs = [&](auto root){return !root ? 1 : root->val = lb * trs(root->left) + rb * trs(root->right) + root->val + mb;};
        function<bool(TreeNode*, int)> dfs = [&](auto root, int k){return root && (root->val == k || dfs(root->left, k) || dfs(root->right, k));};
        return dfs((trs(root), root), trs(subRoot));
    }
};

// 作者：MuriyaTensei
// 链接：https://leetcode-cn.com/problems/subtree-of-another-tree/solution/c-dfs-ha-xi-jiu-ji-jian-ji-ban-ben-by-me-exnn/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。