class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        int n = nums.size(), m = muls.size();
        vector<vector<long long>> f(1005, vector<long long>(1005, LONG_LONG_MIN));
        f[0][0] = 0;
        for(int k = 1; k <= m; ++k) {
            for(int i = 0; i <= k; ++i){
                int j = k - i;
                if(i) f[i][j] = max(f[i][j], f[i - 1][j] + nums[i - 1] * muls[k - 1]);
                if(j) f[i][j] = max(f[i][j], f[i][j - 1] + nums[n - j] * muls[k - 1]);
            }
        }
        long long ans = -2e9;
        for (int i = 0; i <= m; ++i) {
            ans = std::max(ans, f[i][m - i]);
        }
        return ans;
    }
};