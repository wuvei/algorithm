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
    enum stat {COV, NOCOV, MONI, ERROR};
    stat dfs(TreeNode *root) {
        if (!root) return COV;
        stat n1 = dfs(root -> left), n2 = dfs(root -> right);
        
        if (n1 == COV && n2 == COV) return NOCOV;
        
        if (n1 == NOCOV || n2 == NOCOV) {
            ++monitors;
            return MONI;
        }
        if (n1 == MONI || n2 == MONI) return COV;
        
        return ERROR;
    }
    int minCameraCover(TreeNode* root) {
        monitors = 0;
        if (dfs(root) == NOCOV) ++monitors;
        return monitors;
    }
private:
    int monitors;
};


// Tree DP
class Solution {
public:    
    vector<int> dfs(TreeNode* root) {
        vector<int> f(3), fl(3), fr(3);
        f[1] = 1;

        auto l = root -> left, r = root -> right;
        if(l) {
            fl = dfs(l);

            f[0] += min(fl[1], fl[2]);
            f[1] += min({fl[0], fl[1], fl[2]});
        }
        if(r) {
            fr = dfs(r);

            f[0] += min(fr[1], fr[2]);
            f[1] += min({fr[0], fr[1], fr[2]});
        }

        //单独计算f2
        f[2] = 1e8;
        if(l) {
            f[2] = min(f[2], f[0] - min(fl[1], fl[2]) + fl[1]);
        }
        if(r) {
            f[2] = min(f[2], f[0] - min(fr[1], fr[2]) + fr[1]);
        }
        return std::move(f);
    }

    int minCameraCover(TreeNode* root) {
        vector<int> f = dfs(root);
        return min(f[1], f[2]);
    }
};