class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        if (nums.size() == k) return vector<int>(nums);
        vector<int> ans(k, 0);
        int n = nums.size(), j = 0;
        for (int i = 0; i < n; i++) {
            while (j + n - i > k && j && ans[j - 1] > nums[i]) j--;
            if (j < k) ans[j++] = nums[i];
        }
        return ans;
    }
};