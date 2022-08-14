class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minval = 0, cur = 0;
        for (int e: nums) {
            cur += e;
            minval = min(minval, cur);
        }
        return minval < 0 ? 1 - minval : 1;
    }
};