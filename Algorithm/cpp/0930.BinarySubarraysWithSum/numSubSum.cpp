class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0, presum = 0, target;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            target = presum - goal;
            if (m.count(target)) ans += m[target];
            m[presum]++;
        }
        return ans;
    }
};