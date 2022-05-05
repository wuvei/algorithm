class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> rv;
        for (int i = 0; i < ranges.size(); i++) {
            rv.push_back({i - ranges[i], i + ranges[i]});
        }
        sort(rv.begin(), rv.end());
        if (rv[0].first > 0) return -1;
        int cur = 0, ans = 0, i = 0;
        while (i < rv.size()) {
            ans++;
            int pre = cur;
            while (i < rv.size() && rv[i].first <= pre) {
                cur = std::max(cur, rv[i].second);
                i++;
            }
            if (i >= rv.size()) break;
            if (cur == pre) return -1;
            if (cur >= n) return ans;
        }
        if (cur < n) return -1;
        return ans;
    }
};