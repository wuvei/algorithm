class Solution {
public:
    bool ifPred(string &s1, string &s2) {
        int i1 = 0, i2 = 0;
        while (i1 < s1.size() && i2 < s2.size()) {
            while (i2 < s2.size() && s1[i1] != s2[i2])
                ++i2;
            if (i2 < s2.size()) {
                ++i1;
                ++i2;
            }
        }
        return i1 == s1.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [] (const string &s1, const string &s2) {
            if (s1.size() == s2.size()) return s1 < s2;
            return s1.size() < s2.size();
        });
        vector<int> dp(words.size(), 1);
        int ans = 1;
        for (int i = 1; i < words.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (words[j].size() < words[i].size() - 1) break;
                if (words[j].size() == words[i].size() - 1 && ifPred(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(dp[i], ans);
                }
            }
        }
        return ans;
    }
};