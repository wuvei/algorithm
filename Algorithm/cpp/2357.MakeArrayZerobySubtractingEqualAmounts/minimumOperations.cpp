class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool cnt[101]{};
        int ans = 0;
        for (int e: nums) {
            if (!e || cnt[e]) continue;
            ++ans;
            cnt[e] = true;
        }
        return ans;
    }
};