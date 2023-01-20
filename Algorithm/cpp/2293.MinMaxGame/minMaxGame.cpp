class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        while (n > 1) {
            for (int i = 0; i < n >> 1; ++i) {
                int j = i << 1;
                if (i & 1) nums[i] = std::max(nums[j], nums[j + 1]);
                else nums[i] = std::min(nums[j], nums[j + 1]);
            }
            n >>= 1;
        }
        return nums[0];
    }
};