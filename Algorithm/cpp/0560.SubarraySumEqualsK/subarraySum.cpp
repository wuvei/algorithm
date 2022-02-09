class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        int pre = 0, ans = 0;
        for (int e: nums) {
            pre += e;
            ans += count[pre - k];
            count[pre]++;
        }
        return ans;
    }
};