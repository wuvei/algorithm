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
    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        vs.clear();
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *root) {
        vs.push_back(root->val);
        if (!(root -> left) && !(root -> right)) ans.push_back(join());
        else {
            if (root -> left) dfs(root -> left);
            if (root -> right) dfs(root -> right);
        }
        vs.pop_back();
    }

    string join() {
        return std::accumulate(vs.begin() + 1, vs.end(), to_string(vs[0]),
                                [](string &ss, int val)
                                {
                                    return ss + "->" + to_string(val);
                                });
    }

private:
    vector<int> vs;
    vector<string> ans;
};