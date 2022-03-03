#include <cstdio> 
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* check(TreeNode *root) {
        if (!root) return nullptr;
        if (root -> val < l)
            return check(root -> right);
        if (root -> val > h) 
            return check(root -> left);
        
        root -> left = check(root -> left);
        root -> right = check(root -> right);
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        this -> l = low;
        this -> h = high;
        return check(root);
    }
private:
    int l, h;
};

class Solution2 {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return nullptr;

        // 处理头结点，让root移动到[L, R] 范围内，注意是左闭右闭
        while (root && (root -> val < L || root -> val > R)) {
            if (root -> val < L) root = root -> right; // 小于L往右走
            else root = root->left; // 大于R往左走
        }
        TreeNode *cur = root;
        // 此时root已经在[L, R] 范围内，处理左孩子元素小于L的情况
        while (cur) {
            while (cur -> left && cur -> left -> val < L) {
                cur -> left = cur -> left -> right;
            }
            cur = cur -> left;
        }
        cur = root;

        // 此时root已经在[L, R] 范围内，处理右孩子大于R的情况
        while (cur) {
            while (cur -> right && cur -> right -> val > R) {
                cur -> right = cur -> right -> left;
            }
            cur = cur -> right;
        }
        return root;
    }
};

// 作者：carlsun-2
// 链接：https://leetcode-cn.com/problems/trim-a-binary-search-tree/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-er-ch-mebi/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main()
{
    // TreeNode root(4);
    TreeNode *root = new TreeNode(4);
    root -> left = new TreeNode(3);
    Solution s;
    TreeNode *t = s.trimBST(root, 1, 3);
    return 0;
}