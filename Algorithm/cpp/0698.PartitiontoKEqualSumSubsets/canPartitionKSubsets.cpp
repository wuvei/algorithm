class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k) {
            return false;
        }
        s /= k;
        int n = nums.size();
        vector<int> cur(k);
        function<bool(int)> dfs;
        dfs = [&](int i) {
            if (i == n) {
                return true;
            }
            for (int j = 0; j < k; ++j) {
                if (j && cur[j] == cur[j - 1]) {
                    continue;
                }
                cur[j] += nums[i];
                if (cur[j] <= s && dfs(i + 1)) {
                    return true;
                }
                cur[j] -= nums[i];
            }
            return false;
        };
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(0);
    }
};

// 作者：lcbin
// 链接：https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/solution/by-lcbin-92ll/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。