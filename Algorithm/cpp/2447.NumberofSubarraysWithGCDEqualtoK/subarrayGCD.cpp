class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = __gcd(g, nums[j]);
                if (g == k) ++ans;
                else if (g < k) break;
            }
        }
        return ans;
    }
};
