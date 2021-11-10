class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int count[14] = {}, Max = -1, Min = 14;
        for (int n: nums) {
            count[n]++;
            if (n > 0) {
                if (count[n] > 1) return false;
                Max = std::max(Max, n);
                Min = std::min(Min, n);
            }
        }
        if (Max - Min <= 4) return true;
        return false;
    }
};