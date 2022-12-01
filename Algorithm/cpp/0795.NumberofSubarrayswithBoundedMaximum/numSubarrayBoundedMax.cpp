class Solution {
public:
    int numSubarrayBoundedMax(vector<int> &nums, int a, int b) {
        int n = nums.size(), ans = 0;
        for (int i = 0, j = -1, k = -1; i < n; ++i) {
            if (nums[i] > b) {
                k = i;
            } else {
                if (nums[i] < a) {
                    if (j > k) ans += j - k;
                } else {
                    ans += i - k;
                    j = i;
                }
            }
        }
        return ans;
    }
};