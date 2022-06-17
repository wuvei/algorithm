class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int temp = 0, ans = -1, t = accumulate(nums.begin(), nums.end(), 0) - x;
        if (t < 0) return -1;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            temp += nums[r];
            while (temp > t)
                temp -= nums[l++];
            if (temp == t)
                ans = std::max(ans, r - l + 1);
        }
        return ans == -1? -1: nums.size() - ans;
    }
};