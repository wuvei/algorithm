class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<unordered_set<int> > > dp(n + 1, vector<unordered_set<int> >(m + 1));
        dp[0][0].emplace(0);
        vector<vector<vector<bool> > > visited(n + 1, vector<vector<bool> >(m + 1, vector<bool>(2000, false)));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int delta: dp[i][j]) {
                    if (visited[i][j][delta + 1000]) continue;
                    visited[i][j][delta + 1000] = true;
                    int num = 0;
                    if (delta <= 0) {
                        for (int p = i; p < n && isdigit(s1[p]); ++p) {
                            num = num * 10 + s1[p] - '0';
                            dp[p + 1][j].emplace(delta + num);
                        }
                    }
                    num = 0;
                    if (delta >= 0) {
                        for (int q = j; q < m && isdigit(s2[q]); ++q) {
                            num = num * 10 + s2[q] - '0';
                            dp[i][q+1].emplace(delta - num);
                        }
                    }

                    if (i < n && delta < 0 && !isdigit(s1[i]))
                        dp[i + 1][j].emplace(delta + 1);
                    if (j < m && delta > 0 && !isdigit(s2[j]))
                        dp[i][j + 1].emplace(delta - 1);
                    if (i < n && j < m && delta == 0 && s1[i] == s2[j])
                        dp[i + 1][j + 1].emplace(0);
                }
            }
        }
        return dp[n][m].count(0);
    }
};


class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        s1 += ":"; s2 += ":";
        unordered_set<int> seen;
        function<bool(int, int, int, int)> DFS = [&](int i, int j, int d, int n) {
            int a = s1[i] - '0', b = s2[j] - '0', dn = d + n;
            return !n && !seen.insert(i * 10000 + j * 1000 + d).second ? false
                 : a < 10 ? n > 0 && DFS(i + 1, j, d, 10 * n + a) || DFS(i + 1, j, dn, a)
                 : b < 10 ? n < 0 && DFS(i, j + 1, d, 10 * n - b) || DFS(i, j + 1, dn, -b)
                 : dn < 0 ? a > 10 && DFS(i + 1, j, dn + 1, 0)
                 : dn > 0 ? b > 10 && DFS(i, j + 1, dn - 1, 0)
                 : a == b && (a == 10 || DFS(i + 1, j + 1, 0, 0));
        };
        return DFS(0, 0, 0, 0);
    }
};