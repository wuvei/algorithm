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
private:
    int odd_count = 0, ans = 0;
    unordered_map<int, int> count;
public:
    void dfs (TreeNode *root) {
        int e = root->val;
        ++count[e];
        if (count[e] & 1) {
            ++odd_count;
        }
        else {
            --odd_count;
        }
        if (!root->left && !root->right) {
            if (odd_count <= 1) {
                ++ans;
            }
        }
        else {
            if (root->left) {
                dfs(root->left);
            }
            if (root->right) {
                dfs(root->right);
            }
        }
        --count[e];
        if (count[e] & 1) {
            ++odd_count;
        }
        else {
            --odd_count;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        odd_count = ans = 0;
        count.clear();
        dfs(root);
        return ans;
    }
};

// Bit
class Solution {
private:
    int ans = 0;
public:
    void dfs (TreeNode *root, int count) {
        count ^= (1 << root->val);
       
        if (!root->left && !root->right) {
            if (!count || !(count & (count - 1))) {
                ++ans;
            }
        }
        else {
            if (root->left) {
                dfs(root->left, count);
            }
            if (root->right) {
                dfs(root->right, count);
            }
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};