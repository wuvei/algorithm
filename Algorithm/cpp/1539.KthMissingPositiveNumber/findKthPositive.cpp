class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0] > k) return k;
        int low = 0, high = arr.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if (arr[mid] - mid - 1 < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low + k;
    }
};

// https://leetcode.com/problems/kth-missing-positive-number/solutions/3262334/day-65-binary-seach-o-logn-time-o-1-space-easiest-beginner-friendly-sol/
