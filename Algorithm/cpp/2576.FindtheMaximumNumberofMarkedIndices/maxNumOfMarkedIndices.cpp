class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        for (int j = (n + 1) >> 1; j < n; ++j) {
            if ((nums[i] << 1) <= nums[j]) ++i;
        }
        return i << 1;
    }
};