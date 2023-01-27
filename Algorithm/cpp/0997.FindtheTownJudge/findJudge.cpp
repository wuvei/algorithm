class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt(n + 1, 0);
        vector<bool> t(n + 1, false);
        for (auto &v: trust) {
            ++cnt[v[1]];
            t[v[0]] = true;
        }
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == n - 1 && !t[i]) return i;
        }
        return -1;
    }
};