class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size(), left = 1, right = n - 1;
        if (n == 1) return 0;
        long long left_sum = nums[0], right_sum = std::accumulate(nums.begin(), nums.end(), 0LL) - left_sum, diff = std::abs(left_sum - right_sum / right);
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            left_sum += nums[i];
            right_sum -= nums[i];
            ++left;
            --right;
            long long temp = std::abs(left_sum / left - right_sum / right);
            if (temp < diff) {
                ans = i;
                diff = temp;
            }
        }
        if (diff > (left_sum + nums.back()) / n)
            return n - 1;
        return ans;
    }
};