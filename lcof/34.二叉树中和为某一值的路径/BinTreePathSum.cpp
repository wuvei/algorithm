/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Pop(vector<TreeNode*> &v, vector<int> &rec, int &cur_sum) {
        cur_sum -= v.back() -> val;
        v.pop_back();
        rec.pop_back();
    }
    void Push(vector<TreeNode*> &v, vector<int> &rec, int &cur_sum, TreeNode *node, int a) {
        cur_sum += node -> val;
        v.push_back(node);
        rec[rec.size() - 1] = a;
        rec.push_back(0);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<TreeNode*> v;
        vector<int> rec;
        // value in rec represent children whose parent node has explored. 0: no. 1: left child has been explored. 2: right child.
        v.push_back(root);
        rec.push_back(0);
        int cur_sum = root -> val, last = 0;
        while (!v.empty()) {
            TreeNode *node = v.back();

            if (!(node -> left) && !(node -> right)) {
                if (cur_sum == sum) {
                    res.push_back(vector<int>());
                    for (TreeNode *n: v) {
                        res[last].push_back(n -> val);
                    }
                    last++;
                }
                Pop(v, rec, cur_sum);
                continue;
            }

            if (!rec[rec.size() - 1]) {
                if (node -> left) {
                    Push(v, rec, cur_sum, node -> left, 1);
                    continue;
                }
                else rec[rec.size() - 1] = 1;
                
            }
            if (rec[rec.size() - 1] == 1) {
                if (node -> right) {
                    Push(v, rec, cur_sum, node -> right, 2);
                    continue;
                }
                else rec[rec.size() - 1] = 2;
            }
            if (rec[rec.size() - 1] == 2) Pop(v, rec, cur_sum);
            
        }
        return res;
    }
};