class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, mid = 0;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 先根据 nums[mid] 与 nums[lo] 的关系判断 mid 是在左段还是右段 
            if (nums[mid] >= nums[lo]) {
                // 再判断 target 是在 mid 的左边还是右边，从而调整左右边界 lo 和 hi
                if (target >= nums[lo] && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = low + high + 1 >> 1;
            if(nums[low] <= nums[mid]) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        low = high + 1 < nums.size() ? high + 1 : 0;
// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/gong-shui-san-xie-yan-ge-olognyi-qi-kan-6d969/

        // low 是最小值index
        if (target < nums[0]) {
            high = nums.size() - 1;
        }
        else {
            high = low? low - 1: nums.size() - 1;
            low = 0;
        }

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return nums[low] == target? low: -1;
    }
};