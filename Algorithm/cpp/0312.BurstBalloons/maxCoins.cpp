// dp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return nums[0] * nums[1] + std::max(nums[0], nums[1]);
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int ans = 0, n = nums.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for (int i = 2; i < n; i++) {
            for (int l = 0; l + i < n; l++) {
                int r = l + i;
                for (int k = l + 1; k < r; k++) {
                    dp[l][r] = std::max(dp[l][r], dp[l][k] + dp[k][r] + nums[k] * nums[l] * nums[r]);
                }
            }
        }
        return dp[0][n - 1];
    }
};


// up-down
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        else if (n == 2) return nums[0] * nums[1] + std::max(nums[0], nums[1]);
        val.resize(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++) val[i] = nums[i - 1];
        dp.resize(n + 2, vector<int>(n + 2, 0));
        return solve(0, n + 1);
    }

    int solve(int l, int r) {
        if (l == r - 1) return 0;
        if (dp[l][r] != 0) return dp[l][r];
        int max = 0, x = val[l] * val[r];
        for (int i = l + 1; i < r; i++) {
            int temp = solve(l, i) + solve(i, r) + x * val[i];
            if (max < temp) max = temp;
        }
        dp[l][r] = max;
        return max;
    }
private:
    vector<vector<int> > dp;
    vector<int> val;
};