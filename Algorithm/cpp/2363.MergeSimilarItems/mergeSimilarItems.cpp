class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<int> count(1001, 0);
        for (auto &v: items1) count[v[0]] += v[1];
        for (auto &v: items2) count[v[0]] += v[1];
        vector<vector<int>> ans;
        ans.reserve(items1.size() + items2.size());
        for (int i = 0; i < count.size(); ++i) {
            if (!count[i]) continue;
            ans.push_back({i, count[i]});
        }
        return std::move(ans);
    }
};