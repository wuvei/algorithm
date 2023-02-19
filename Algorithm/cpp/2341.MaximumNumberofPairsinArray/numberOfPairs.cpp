class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int cnt[101]{};
        vector<int> ans(2, 0);
        for (int e: nums) {
            ++cnt[e];
            ++ans[1];
            if (cnt[e] == 2) {
                cnt[e] = 0;
                ++ans[0];
                ans[1] -= 2;
            }
        }
        return ans;
    }
};