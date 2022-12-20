class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = l + ((r - l) >> 1), ops = 0;
            for (int e: nums) ops += (e - 1) / mid;
            if (ops <= maxOperations) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};