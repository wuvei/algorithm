class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums[0];
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (smallerOrEqual(nums, mid) < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    
    int smallerOrEqual(vector<int>& nums, int val) {
        int sum = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            while (j < nums.size() && nums[j] - nums[i] <= val) j++;
            sum += j - i - 1;
        }
        return sum;
    }
};