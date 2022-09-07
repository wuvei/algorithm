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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int> > m;
        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});
        while (!q.empty()) {
            int len = q.size();
            unordered_map<int, multiset<int> > temp;
            while (len--) {
                auto [node, col] = q.front();
                q.pop();
                temp[col].insert(node->val);
                if (node->left) q.push({node->left, col - 1});
                if (node->right) q.push({node->right, col + 1});
            }
            for (auto it: temp) {
                auto &[e, ms] = it;
                m[e].reserve(m[e].size() + ms.size());
                m[e].insert(m[e].end(), ms.begin(), ms.end());
            }
        }
        vector<vector<int> > ans;
        for (auto it: m) {
            ans.push_back(it.second);
        }
        return ans;
    }
};