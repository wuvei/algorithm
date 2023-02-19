class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int d = nums[0];
        for (int e: nums) {
            d = std::gcd(e, d);
            if (d == 1) return true;
        }
        return false;
    }
};