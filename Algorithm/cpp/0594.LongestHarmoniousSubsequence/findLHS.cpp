// sort
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int begin = 0;
        int res = 0;
        for (int end = 0; end < nums.size(); end++) {
            while (nums[end] - nums[begin] > 1) {
                begin++;
            }
            if (nums[end] - nums[begin] == 1) {
                res = max(res, end - begin + 1);
            }
        }
        return res;
    }
};

// Hash
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int e: nums) m[e]++;
        int ans = 0;
        for (auto &it: m) {
            int val = it.first;
            if (m.find(val + 1) != m.end())
                ans = std::max(ans, it.second + m[val + 1]);
        }
        return ans;
    }
};