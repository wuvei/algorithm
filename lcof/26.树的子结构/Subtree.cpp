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
    bool DoesTree1HasTree2(TreeNode* A, TreeNode* B) {
        if (!B) return true;
        if (!A) return false;
        return (A -> val != B -> val) && DoesTree1HasTree2(A -> left, B -> left) && DoesTree1HasTree2(A -> right, B -> right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        return ((A -> val == B -> val)? DoesTree1HasTree2(A, B): false) || isSubStructure(A -> left, B) || isSubStructure(A -> right, B);
    }
};