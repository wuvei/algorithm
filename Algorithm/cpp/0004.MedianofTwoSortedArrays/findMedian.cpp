class Solution {
public:
    int getK(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int len1 = nums1.size(), len2 = nums2.size();
        int start1 = 0,  start2 = 0;
        while(1) {
            if (start1 == len1) return nums2[start2 + k - 1];
            if (start2 == len2) return nums1[start1 + k - 1];
            if (k == 1) return std::min(nums1[start1], nums2[start2]);
            int idx1 = std::min(start1 + k / 2 - 1, len1 - 1);
            int idx2 = std::min(start2 + k / 2 - 1, len2 - 1);
            if (nums1[idx1] > nums2[idx2]) {
                k -= idx2 - start2 + 1;
                start2 = idx2 + 1;
            }
            else {
                k -= idx1 - start1 + 1;
                start1 = idx1 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2)
            return getK(nums1, nums2, (total+1) / 2);
        else return (getK(nums1, nums2, total / 2) + getK(nums1, nums2, total / 2 + 1)) * 0.5;
    }
};