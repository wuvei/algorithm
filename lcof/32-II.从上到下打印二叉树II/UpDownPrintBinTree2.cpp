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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> one, two;
        queue<TreeNode*> *p1 = &one, *p2 = &two, *temp;
        p1 -> push(root);
        int i = 0;
        while(!one.empty() || !two.empty()) {
            ans.push_back(vector<int>());
            while(!p1 -> empty()) {
                TreeNode *node = p1 -> front();
                p1 -> pop();
                ans[i].push_back(node -> val);
                if (node -> left) p2 -> push(node -> left);
                if (node -> right) p2 -> push(node -> right);
            }
            i++;
            temp = p1;
            p1 = p2;
            p2 = p1;
        }
        return ans;
    }

    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        int num;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            num = Q.size();
            vector<int> arr;
            while(num--){
                TreeNode* tmp = Q.front();
                arr.push_back(tmp -> val);
                Q.pop();
                if(tmp -> left) Q.push(tmp -> left);
                if(tmp -> right) Q.push(tmp -> right);
            }
            result.push_back(arr);
        }
        return result;
    }
};