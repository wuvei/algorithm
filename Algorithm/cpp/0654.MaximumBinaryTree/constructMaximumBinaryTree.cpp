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
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        else if (l == r) return new TreeNode(nums[l]);
        int idx = std::max_element(nums.begin() + l, nums.begin() + r + 1) - nums.begin();
        TreeNode *root = new TreeNode(nums[idx]);
        root->left = helper(nums, l, idx - 1);
        root->right = helper(nums, idx + 1, r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0,  nums.size() - 1);
    }
};

// Monotonic Stack
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        vector<int> stk;
        vector<TreeNode*> tree(n);
        for (int i = 0; i < n; ++i) {
            tree[i] = new TreeNode(nums[i]);
            while (!stk.empty() && nums[i] > nums[stk.back()]) {
                tree[i]->left = tree[stk.back()];
                stk.pop_back();
            }
            if (!stk.empty()) {
                tree[stk.back()]->right = tree[i];
            }
            stk.push_back(i);
        }
        return tree[stk[0]];
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/maximum-binary-tree/solution/zui-da-er-cha-shu-by-leetcode-solution-lbeo/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。