class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        while(l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] < nums[r]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};

// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/er-fen-cha-zhao-wei-shi-yao-zuo-you-bu-dui-cheng-z/
