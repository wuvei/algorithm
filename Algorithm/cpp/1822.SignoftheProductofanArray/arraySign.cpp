class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt_neg = 0;
        for (int e: nums) {
            if (e == 0) return 0;
            else if (e < 0)
                ++cnt_neg;
        }
        return cnt_neg & 1 ? -1 : 1;
    }
};