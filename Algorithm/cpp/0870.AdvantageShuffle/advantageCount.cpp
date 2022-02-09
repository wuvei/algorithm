class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        int n = nums2.size();
        vector<pair<int, int> > n2(n);
        for (int i = 0; i < n; i++)
            n2[i] = {nums2[i], i};
        sort(n2.begin(), n2.end(), greater<>());

        int l = 0, r = n - 1;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (n2[i].first < nums1[r]) {
                ans[n2[i].second] = nums1[r--];
            }
            else {
                ans[n2[i].second] = nums1[l++];
            }
        }
        return ans;
    }
};