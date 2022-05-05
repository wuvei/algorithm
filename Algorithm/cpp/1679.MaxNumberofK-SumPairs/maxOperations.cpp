class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int ans = 0;
        for (int e: nums) {
            int complement = k - e;
            if (count[complement]) {
                --count[complement];
                ++ans;
            }
            else ++count[e];
        }
        return ans;
    }
};