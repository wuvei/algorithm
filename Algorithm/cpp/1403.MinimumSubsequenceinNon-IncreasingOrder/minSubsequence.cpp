class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end(), greater<int>());
        int target = accumulate(nums.begin(), nums.end(), 0), cur = 0;
        target = (target >> 1) + 1;
        
        for (int e: nums) {
            cur += e;
            ans.push_back(e);
            if (cur >= target)
                break;
        }
        return ans;
    }
};