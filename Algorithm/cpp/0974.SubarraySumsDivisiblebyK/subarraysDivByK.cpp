class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int pre = 0, ans = 0;
        for (int e: nums) {
            pre += e;
            int mod = (pre % k + k) % k;
            if(m.count(mod)) {
                ans += m[mod];
            }
            ++m[mod];
        }
        return ans;
    }
};