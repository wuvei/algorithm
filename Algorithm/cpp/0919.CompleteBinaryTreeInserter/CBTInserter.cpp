// Simple BFS
class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> level;
    CBTInserter(TreeNode* _root): root(_root){
        level.push(root);
    }
    
    int insert(int val) {
        TreeNode *nn = new TreeNode(val);
        int parent;
        while(!level.empty()) {
            TreeNode *node = level.front();
            if (node->left && node->right) {
                level.push(node->left);
                level.push(node->right);
                level.pop();
            }
            else {
                parent = node->val;
                if (!node->left)
                    node->left = nn;
                else node->right = nn;
                break;
            }
        }
        return parent;
    }
  
    TreeNode* get_root() {
        return root;
    }
};

// Similar to heap
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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        if (!root) return;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            tree.push_back(node);
            if (node -> left)
                q.push(node -> left);
            if (node -> right)
                q.push(node -> right);
        }
    }
    
    int insert(int val) {
        TreeNode *node = new TreeNode(val);
        tree.push_back(node);
        int idx = tree.size() - 1, p = (idx - 1) >> 1;
        if (idx & 1)
            tree[p] -> left = node;
        else tree[p] -> right = node;
        return tree[p] -> val;
    }
    
    TreeNode* get_root() {
        return tree[0];
    }
private:
    vector<TreeNode *> tree;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
