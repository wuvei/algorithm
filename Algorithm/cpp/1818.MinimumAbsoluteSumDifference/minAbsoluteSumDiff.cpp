class Solution {
public:
    int mod = static_cast<int>(1e9) + 7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> s1(nums1);
        sort(s1.begin(), s1.end());
        int sum = 0, maxn = 0, n = nums1.size();
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) continue;
            int x = abs(nums1[i] - nums2[i]);
            sum = (sum + x) % mod;
            int idx = lower_bound(s1.begin(), s1.end(), nums2[i]) - s1.begin(), nd;
            if (idx < n) 
                maxn = max(maxn, x - (s1[idx] - nums2[i]));
            if (idx > 0) {
                maxn = max(maxn, x - (nums2[i] - s1[idx - 1]));
            }
        }
        return (sum - maxn + mod) % mod;
    }
};