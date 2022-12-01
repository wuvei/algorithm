class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long d = static_cast<long long>(nums[i]) - nums[j];
                dp[i][d] += dp[j][d] + 1;
                // dp[j][d] 联合上 dp[i] 表示了长度至少为3的等差数列
                res += dp[j][d];
            }
        }
        return res;
    }
};

// 作者：微扰理论
// 链接：https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/solutions/928859/dong-tai-gui-hua-deng-chai-shu-lie-shi-y-kxal/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。