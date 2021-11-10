class Solution {
public:
    int ans = 0, m;
    int countMaxOrSubsets(vector<int>& nums) {
        // 按位或是不减的操作，所以全部 | 起来是最大值
        m = 0;
        for(auto p : nums){
            m |= p;
        }
        dfs(nums, 0, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int idx, int cur){
        // 剪枝
        if(cur == m){
            ans += 1 << (nums.size() - idx);
            return;
        }
        if(idx == nums.size()){
            return;
        }
        // 加上这个数
        dfs(nums, idx + 1, cur | nums[idx]);
        // 不加这个数
        dfs(nums, idx + 1, cur);
    }
};

// https://leetcode-cn.com/problems/count-number-of-maximum-bitwise-or-subsets/solution/bao-li-yu-jian-zhi-by-zaozhe-48mi/
