class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
        unordered_map<int, int> count;
        int max_count = 0;
        for (int n: nums) {
            max_count = std::max(max_count, ++count[n]);
        }
        vector<vector<int> > order(max_count + 1, vector<int>());
        for (auto it: count)  {
            order[it.second].push_back(it.first);
        }
        for (int i = max_count, j = 0; j < k && i >= 0; i--)
            for (int n: order[i])
                ans[j++] = n;
        
        return ans;
    }
};