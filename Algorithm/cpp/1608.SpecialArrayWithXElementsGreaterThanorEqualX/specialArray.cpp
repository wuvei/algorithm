class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[n - i]  >= i && nums[n - i - 1] < i) {
                return i;
            }
        }
        if (nums[0] >= n) {
            return n;
        }
        return -1;
    }
};