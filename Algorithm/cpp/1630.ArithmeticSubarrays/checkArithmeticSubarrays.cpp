class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans(m, false);
        for (int i = 0; i < m; ++i) {
            if (r[i] - l[i] == 1) {
                ans[i] = true;
                continue;
            }
            unordered_set<int> s;
            int amin = INT_MAX, amax = INT_MIN;
            for (int j = l[i]; j <= r[i]; ++j) {
                s.insert(nums[j]);
                amin = std::min(amin, nums[j]);
                amax = std::max(amax, nums[j]);
            }
            if (amax == amin) {
                ans[i] = true;
                continue;
            }
            if ((amax - amin) % (r[i] - l[i])) continue;
            int d = (amax - amin) / (r[i] - l[i]);
            bool flag = true;
            for (int j = amin + d; j < amax && flag; j += d) {
                if (!s.count(j)) flag = false;
            }
            ans[i] = flag;
        }
        return std::move(ans);
    }
};