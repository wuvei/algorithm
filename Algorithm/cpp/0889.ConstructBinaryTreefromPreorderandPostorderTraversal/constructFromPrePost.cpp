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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        m.clear();
        pre = preorder;
        post = postorder;
        int n = postorder.size();
        for(int i = 0; i < n; i++) m[post[i]]=i;
        return dfs(0, n - 1, 0, n - 1);
    }
    TreeNode* dfs(int preBeg, int preEnd, int postBeg, int postEnd) {
        if(preBeg > preEnd) return nullptr;
        TreeNode *root = new TreeNode(pre[preBeg]);
        if(preBeg == preEnd) return root;
        int leftRoot = pre[preBeg + 1], endLeft = m[leftRoot], leftLen = endLeft - postBeg + 1;
        root -> left = dfs(preBeg + 1, preBeg + leftLen, postBeg, endLeft);
        root -> right = dfs(preBeg + leftLen + 1, preEnd, postBeg + leftLen, postEnd - 1);
        return root;
    }
private:
    unordered_map<int,int> m;
    vector<int> pre, post;
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) { 
        unordered_map<int,int> m;
        int n = pre.size();
        for(int i = 0; i < n; i++)
            m[post[i]] = i;
        
        stack<TreeNode*> st;
        
        TreeNode *root = new TreeNode(pre[0]);
        st.push(root);
        
        for(int i = 1; i < n; i++) {
            TreeNode *temp = new TreeNode(pre[i]);
            while(m[st.top() -> val] < m[pre[i]])
                st.pop();
            if(!st.top()->left)
                st.top() -> left = temp;
            else st.top() -> right = temp;
            st.push(temp);
        }       
        return root;
    }
};

