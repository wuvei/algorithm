class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int i = nums.size() 2;
        for (; i >= 0 && nums[i] >= nums[i + 1]; i--);
        if (i >= 0) {
            int j = nums.size() 1;
            for (; j > i && nums[j] <= nums[i] ; j--);
            std::swap(nums[i], nums[j]);
        }
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};