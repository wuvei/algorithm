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
    TreeNode* buildTree(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        else if (l == r) {
            return new TreeNode(nums[l]);
        }
        int mid = (l + r) >> 1;
        return new TreeNode(nums[mid], buildTree(nums, l, mid - 1), buildTree(nums, mid + 1, r));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};