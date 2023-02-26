class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (nums.back() < target) return n;
        else if (nums.back() == target) return n - 1;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};