class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        else if (nums.size() == 2) return (nums[0] == nums[1])? 1: 2;
        int inc = 1, dec = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                inc = dec + 1;
            else if (nums[i] < nums[i - 1])
                dec = inc + 1;
        }
        return std::max(inc, dec);
    }
};