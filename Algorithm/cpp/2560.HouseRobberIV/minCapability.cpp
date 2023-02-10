class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        auto check = [&](int lim) -> int {
            int dp0 = 0, dp1 = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= lim) {
                    int tmp = std::max(dp1, dp0 + 1);
                    dp0 = dp1;
                    dp1 = tmp;
                }
                else dp0 = dp1;
            }
            return dp1;
        };
        int l = 0, r = *std::max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid) >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};