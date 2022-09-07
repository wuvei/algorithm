class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = -1;
        for (int e: nums) {
            if (e > max1) {
                max2 = max1;
                max1 = e;
            }
            else if (e > max2) {
                max2 = e;
            }
        }
        return (max1 - 1) * (max2 - 1);
    }
};