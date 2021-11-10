class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        vector<int> re;
        while (l <= r) {
            while (l <= r && nums[l] + nums[r] < target) l++;
            while (l <= r && nums[l] + nums[r] > target) r--;
            if (l <= r && nums[l] + nums[r] == target) {
                re.push_back(nums[l]);
                re.push_back(nums[r]);
                break;
            }
        }
        return re;
    }
};