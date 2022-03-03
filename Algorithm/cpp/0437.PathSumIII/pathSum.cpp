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
    vector<int> getSum(TreeNode *root) {
        if (!root) return {};
        vector<int> left = getSum(root -> left), right = getSum(root -> right);
        vector<int> sum(left.size() + right.size() + 1);
        int i = 0, cur = root -> val;
        if (cur == target) ans++;
        sum[i++] = cur;
        for (int e: left) {
            sum[i] = cur + e;
            if (sum[i++] == target) ans++;
        }
        for (int e: right) {
            sum[i] = cur + e;
            if (sum[i++] == target) ans++;
        }
        vector<int>().swap(left);
        vector<int>().swap(right);
        return std::move(sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        this -> ans = 0;
        this -> target = targetSum;
        getSum(root);
        return ans;
    }
private:
    int target, ans;
};


// // prefix sum
class Solution {
public:
     void solve(TreeNode *root, int sum){
        if(!root) return;
        sum += root->val;
        ans += preSum[sum - target];
        preSum[sum]++;
        solve(root -> left, sum);
        solve(root -> right, sum);
        preSum[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        preSum[0] = 1;
        ans = 0;
        target = targetSum;
        solve(root, 0);
        return ans;
    }
    
private:
    unordered_map<int,int> preSum;
    int ans, target;
};

