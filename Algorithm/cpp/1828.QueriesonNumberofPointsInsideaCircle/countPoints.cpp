class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int t = 0;
            for (auto &v: points) {
                if ((v[0] - queries[i][0]) * (v[0] - queries[i][0]) + (v[1] - queries[i][1]) * (v[1] - queries[i][1]) <= queries[i][2] * queries[i][2]) ++t;
            }
            ans[i] = t;
        }
        return ans;
    }
};