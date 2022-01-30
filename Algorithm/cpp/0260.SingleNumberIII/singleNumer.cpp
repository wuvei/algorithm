class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0, a = 0, b = 0;
        for (int e: nums) x ^= e;
        x = x == INT_MIN ? 0 : x & (-x);
        for (int e: nums)
          (e & x) ? a ^= e : b ^= e;
        return {a,b};
    }
};