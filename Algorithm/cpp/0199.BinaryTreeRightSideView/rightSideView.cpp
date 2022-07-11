// BFS
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
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
                if (i == size - 1)
                    ans.push_back(node -> val);
            }
        }
        return ans;
    }
};


// DFS
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        res.clear();
        if (!root) return res;
        dfs(root, 0);
        return res;
	}

    void dfs(TreeNode *root, int depth) {
        if (depth == res.size())
            res.push_back(root -> val);
        if (root -> right) dfs(root -> right, depth + 1);
        if (root -> left) dfs(root -> left, depth + 1);
    }
private:
    vector<int> res;
};