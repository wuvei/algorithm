class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), right = n - 1;
        while (right && arr[right] >= arr[right - 1])
            --right;
        
        if (right == 0)
            return 0;

        int ans = right;
        for (int left = 0; left == 0 || arr[left - 1] <= arr[left]; ++left) {
            while (right < n && arr[right] < arr[left])
                ++right;
            ans = min(ans, right - left - 1);
        }
        return ans;
    }
};