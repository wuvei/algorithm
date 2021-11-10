class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int len = nums.size();
        if (len < 3) return ret;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < len; first++) {
            if (nums[first] > 0) break;
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            int target = -nums[first];
            for (int second = first + 1, third = len - 1; second < len; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;
                while (second < third && nums[second] + nums[third] > target) third--;
                if (second == third) break;
                if (nums[second] + nums[third] == target) ret.push_back({nums[first], nums[second], nums[third]});
            }
        }
        return ret;
    }
};

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int len = nums.size();
        if (len < 3) return ret;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < len; first++) {
            if (nums[first] > 0) break;
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            int second = first + 1, third = len - 1;
            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == 0) {
                    ret.push_back({nums[first], nums[second], nums[third]});
                    while (second < third && nums[second] == nums[second + 1]) second++;
                    while (second < third && nums[third] == nums[third - 1]) third--;
                    second++;
                    third--;
                }
                else if (sum > 0) third--;
                else second++;
            }
        }
        return ret;
    }
};