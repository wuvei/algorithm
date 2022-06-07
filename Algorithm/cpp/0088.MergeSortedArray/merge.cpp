class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, ind = nums1.size() - 1;
        while (ind >= 0) {
            if (p1 >= 0 && p2 >= 0) {
                nums1[ind--] = (nums1[p1] > nums2[p2])? nums1[p1--]: nums2[p2--]; 
            }
            else if (p1 >= 0) return;
            else {
                std::copy(nums2.begin(), nums2.begin() + p2 + 1, nums1.begin());
                return;
            }
        }
    }
};