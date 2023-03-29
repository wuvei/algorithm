class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> cnt;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int t = nums[i] + nums[i + 1];
            if (cnt.count(t)) return true;
            cnt.insert(t);
        }
        return false;
    }
};