class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, temp = 0;
        unordered_map<int, int> m;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            int val = nums[r];
            ++m[val];
            temp += val;
            while (m[val] > 1) {
                temp -= nums[l];
                --m[nums[l++]];
            }
            ans = std::max(ans, temp);
        }
        return ans;
    }
};