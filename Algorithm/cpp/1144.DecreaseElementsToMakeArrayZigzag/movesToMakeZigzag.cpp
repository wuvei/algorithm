class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int ans[2]{}, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int l = i > 0 ? nums[i - 1] : 1001;
            int r = i + 1 < n ? nums[i + 1] : 1001;
            int m = std::min(l, r);
            if (nums[i] >= m) {
                ans[i & 1] += nums[i] - m + 1;
            }
        }
        return std::min(ans[0], ans[1]);
    }
};