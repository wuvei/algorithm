class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int l = 1, r = 1;
        for (int i = 0; i < n; i++) {
            ans[i] *= l;
            l *= nums[i];
            ans[n - 1 - i] *= r;
            r *= nums[n - 1 - i];
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int t = nums[0];
        for (int i = 1; i < n; i++) {
            ans[i] = t;
            t *= nums[i];
        }
        t = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans[i] *= t;
            t *= nums[i];
        }
        return ans;
    }
};