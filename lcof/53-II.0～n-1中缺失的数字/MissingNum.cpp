class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 1 - nums[0];
        int start = 0, end = len - 1, mid;
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] > mid)
            {
                if (!mid || nums[mid - 1] == mid - 1) return mid;
                else end = mid - 1;
            }
            else {
                if (mid == len - 1 || nums[mid + 1] > mid + 1) return mid + 1;
                else start = mid + 1;
            }
        }
        return start == 0? 0: len;
    }

    int missingNumber2(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] != mid)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return i;
    }
};