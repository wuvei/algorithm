class Solution {
public:
    const int mod = static_cast<int>(1e9) + 7;
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> hor;
        for (auto &v: rectangles) {
            hor.push_back(v[0]);
            hor.push_back(v[2]);
        }
        sort(hor.begin(), hor.end());
        long long ans = 0;
        for (int i = 1; i < hor.size(); ++i) {
            int a = hor[i - 1], b = hor[i], len = b - a;
            if (!len) {
                continue;
            }
            vector<pair<int, int>> lines;
            for (auto &v: rectangles) {
                if (v[0] <= a && b <= v[2]) {
                    lines.push_back({v[1], v[3]});
                }
            }
            sort(lines.begin(), lines.end());
            long long total = 0, l = -1, r = -1;
            for (auto &cur: lines) {
                if (cur.first > r) {
                    total += r - l;
                    l = cur.first;
                    r = cur.second;
                }
                else if (cur.second > r) {
                    r = cur.second;
                }
            }
            total += r - l;
            ans += (total * len) % mod;
            ans %= mod;
        }
        return static_cast<int>(ans);
    }
};
