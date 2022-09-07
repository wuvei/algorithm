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
    vector<vector<unsigned long long> > m;
    void dfs(TreeNode *root, int level, unsigned long long idx) {
        if (m.size() < level)
            m.push_back({idx});
        else m[level - 1].push_back(idx);
        if (root->left) dfs(root->left, level + 1, idx << 1);
        if (root->right) dfs(root->right, level + 1, (idx << 1) + 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 1, 1);
        int ans = 1;
        for (auto &v: m) {
            int temp = v.back() - v[0] + 1;
            ans = max(temp, ans);
        }
        return ans;
    }
};

// BFS
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int> > q;
        int res = 0;
        q.push({root, 0});
        while(!q.empty()) {
            int len=q.size(), start=q.front().second, end=q.back().second;
            res = max(res, end - start + 1);
            for(int i = 0; i < len; ++i) {
                auto &[node, idx] = q.front();
                if(node->left)
                    q.push({node->left, (long long)2*idx + 1});
                
                if(node->right)
                    q.push({node->right, (long long)2*idx + 2});
                q.pop();
            }
            
        }
        return res;
    }
};