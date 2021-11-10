class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int lcis = 1, current = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) current++;
            else {
                if (lcis < current) lcis = current;
                current = 1;
            }
        }
        return std::max(current, lcis);
    }
};