class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0, ans = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ans = std::max(ans, (sum + i) / (i + 1));
        }
        return static_cast<int>(ans);
    }
};