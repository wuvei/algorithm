class Solution {
public:
    int calc(int x) {
        return (x <= 1)? x : ((x <= 9)? 2 : ((x <= 99)? 3 : 4));
    }

    int getLengthOfOptimalCompression(string s, int k) {
        int T = s.size() - k;

        vector<vector<int>> dp(s.size() + 1, vector<int>(T + 1, 100000));
        dp[s.size()][T] = 0; // 初始条件

        for(int p = s.size() - 1; p >= 0; --p) {
            for(int cnt = 0; cnt <= T; ++cnt) {
                // 1. 从此开始选择连续的字符
                for(int j = p, same = 0; j < s.size(); ++j) {
                    same += (s[j] == s[p]);
                    if(same + cnt > T)
                        break;
                    dp[p][cnt] = min(dp[p][cnt], calc(same) + dp[j+1][cnt + same]);
                }
                // 2. 跳过该字符
                dp[p][cnt] = min(dp[p][cnt], dp[p+1][cnt]);
            }
        }

        return dp[0][0];
    }
};