class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int maxI = -1, minI = -1, i0 = -1, x;
        for (int i = 0; i < nums.size(); ++i) {
            x = nums[i];
            if (x == minK) minI = i;
            if (x == maxK) maxI = i;
            if (x < minK || x > maxK) i0 = i;
            ans += std::max(std::min(minI, maxI) - i0, 0);
        }
        return ans;
    }
};