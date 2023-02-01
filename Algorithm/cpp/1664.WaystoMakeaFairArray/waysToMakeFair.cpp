class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_even(n + 1, 0), prefix_odd(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (i & 1) {
                prefix_even[i] = prefix_even[i - 1] + nums[i - 1];
                prefix_odd[i] = prefix_odd[i - 1];
            }
            else {
                prefix_odd[i] = prefix_odd[i - 1] + nums[i - 1];
                prefix_even[i] = prefix_even[i - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int odd = prefix_odd[i] + prefix_even[n] - prefix_even[i + 1],
            even = prefix_even[i] + prefix_odd[n] - prefix_odd[i + 1];
            if (even == odd) ++ans;
        }
        return ans;
    }
};

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size(), sum_even = 0, sum_odd = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) sum_odd += nums[i];
            else sum_even += nums[i];
        }
        int ans = 0, even = 0, odd = 0;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            if (i & 1) {
                if (odd + sum_even - even == even + sum_odd - odd - v) ++ans;
                odd += nums[i];
            }
            else {
                if (odd + sum_even - even - v == even + sum_odd - odd) ++ans;
                even += nums[i];
            }
        }
        return ans;
    }
};