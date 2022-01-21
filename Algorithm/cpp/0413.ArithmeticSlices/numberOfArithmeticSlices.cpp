// [1,2,3]: 1
// [1,2,3,4]: 3
// [1,2,3,4,5]: 6
// [1,2,3,4,5,6]: 10
// Find: Suppose the number of slices is n-1 when
// the length of the consecutive arithmetic array is dp,
// then that of such array with length n is dp + (n-2).
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int dp = 2, ans = 0;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp++;
                ans += dp-2;
            }
            else dp = 2;
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int dp = 0, ans = 0;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp++;
                ans += dp;
            }
            else dp = 0;
        }
        return ans;
    }
};