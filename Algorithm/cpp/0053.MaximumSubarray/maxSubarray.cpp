class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], pre = nums[0], cur;
        for (int i = 1; i < nums.size(); i++) {
            cur = nums[i] + (pre < 0? 0: pre);
            ans = std::max(ans, cur);
            pre = cur;
        }
        return ans;
    }
};