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
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<TreeNode*> > layer;
        queue<TreeNode*> q;
        q.push(root);
        bool if_last_layer = false;
        while (!if_last_layer) {
            int len = q.size();
            if_last_layer = true;
            vector<TreeNode*> l;
            for (int i = 0; i < len; ++i) {
                TreeNode *node = q.front();
                q.pop();
                l.push_back(node);
                if (node && (node->left || node->right))
                    if_last_layer = false;
                if(node) {
                    q.push(node->left);
                    q.push(node->right);
                }
                else {
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }
            layer.push_back(l);
        }
        int x = (1 << layer.size()) - 1;
        vector<vector<string> > ans(layer.size(), vector<string>(x, ""));
        for (int i = 0; i < layer.size(); ++i) {
            int step = (x + 1) >> i, begin = x >> (i + 1);
            for (int j = begin, k = 0; k < layer[i].size(); ++k, j += step) {
                if (layer[i][k])
                    ans[i][j] = to_string(layer[i][k]->val);
            }
        }
        return ans;
    }
};

// DFS
class Solution {
    int h = 0, m = 0, n = 0;
    vector<vector<string>> ans;
public:
    vector<vector<string>> printTree(TreeNode *root) {
        dfs1(root, 0);
        m = h + 1; n = (1 << (h + 1)) - 1;
        ans.resize(m, vector<string>(n, ""));
        dfs2(root, 0, (n - 1) / 2);
        return ans;
    }
    void dfs1(TreeNode *root, int depth) {
        if (!root) return;
        h = max(h, depth);
        dfs1(root->left, depth + 1);
        dfs1(root->right, depth + 1);
    }
    void dfs2(TreeNode *root, int x, int y) {
        if (!root) return;
        ans[x][y] = to_string(root->val);
        if (h - x - 1 < 0)
            return;
        dfs2(root->left, x + 1, y - (1 << (h - x - 1)));
        dfs2(root->right, x + 1, y + (1 << (h - x - 1)));
    }
};

// https://leetcode.cn/problems/print-binary-tree/solution/by-ac_oier-mays/