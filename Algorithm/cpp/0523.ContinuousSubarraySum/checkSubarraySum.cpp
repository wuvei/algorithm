class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        unordered_map<int, int> m;
        m[0] = -1;
        int remainder = 0;
        for (int i = 0; i < n; i++) {
            remainder = (remainder + nums[i]) % k;
            if (m.count(remainder)) {
                if (i - m[remainder] >= 2) {
                    return true;
                }
            } else {
                m[remainder] = i;
            }
        }
        return false;
    }
};