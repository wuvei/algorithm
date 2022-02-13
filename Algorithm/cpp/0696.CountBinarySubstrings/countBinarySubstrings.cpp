class Solution {
public:
    int countBinarySubstrings(string s) {
        char cur = s[0];
        int cnt = 0, pre = 0, ans = 0;
        for (char c: s) {
            if (cur == c) cnt++;
            else {
                ans += std::min(pre, cnt);
                pre = cnt;
                cnt = 1;
                cur = c;
            }
        }
        return ans + std::min(pre, cnt);
    }
};