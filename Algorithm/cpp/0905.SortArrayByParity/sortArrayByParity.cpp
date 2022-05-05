// Two Pointers
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            while (l < r && !(nums[l] & 1)) ++l;
            while (l < r && (nums[r] & 1)) --r;
            if (l < r) swap(nums[l], nums[r]);
            ++l;
            --r;
        }
        return nums;
    }
};