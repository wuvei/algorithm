class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt[251]{}, ans = 0;
        for (int e : nums) {
            if (cnt[e] >= 2) ++ans;
            cnt[e + diff] = cnt[e] + 1;
        }
        return ans;
    }
};