class Solution {
public:
    int cntPalindromic(string &s, int l, int r) {
        int cnt = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int ans = cntPalindromic(s, 0, 0);
        for (int i = 1; i < s.size(); i++) {
            ans += cntPalindromic(s, i, i);
            if (s[i - 1] == s[i])
                ans += cntPalindromic(s, i - 1, i);
        }
        return ans;
    }
};

func countSubstrings(s string) int {
    count := 0
    dp := make([]bool, len(s))

    for j := 0; j < len(s); j++ {
        for i := 0; i <= j; i++ {
            if i == j {
                dp[i] = true
                count++
            } else if j-i == 1 && s[i] == s[j] {
                dp[i] = true
                count++
            } else if j-i > 1 && s[i] == s[j] && dp[i+1] {
                dp[i] = true
                count++
            } else {
                dp[i] = false
            }
        }
    }
    return count
}

// DP
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    result++;
                    dp[i][j] = true;
                }
            }
        }
        return result;
    }
};


// Manacher 算法
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        string t = "$#";
        for (const char &c: s) {
            t += c;
            t += '#';
        }
        n = t.size();
        t += '!';

        auto f = vector <int> (n);
        int iMax = 0, rMax = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            // 初始化 f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
            // 中心拓展
            while (t[i + f[i]] == t[i - f[i]]) ++f[i];
            // 动态维护 iMax 和 rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
            ans += (f[i] / 2);
        }

        return ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/palindromic-substrings/solution/hui-wen-zi-chuan-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。