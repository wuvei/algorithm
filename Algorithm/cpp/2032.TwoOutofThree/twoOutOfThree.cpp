class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int count[101]{};
        for (int e: nums1)
            count[e] = 1;
        for (int e: nums2)
            count[e] |= 2;
        for (int e: nums3)
            count[e] |= 4;
        vector<int> ans;
        for (int i = 1; i <= 100; ++i) {
            if (count[i] >= 3 && count[i] != 4)
            // if (count[i] & count[i]-1)
                ans.push_back(i);
        }
        return std::move(ans);
    }
};