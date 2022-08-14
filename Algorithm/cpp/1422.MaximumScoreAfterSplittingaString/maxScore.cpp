class Solution {
public:
    int maxScore(string s) {
        int ans = 0, cur = 0;
        for (char c: s) cur += c - '0';
        for (char c: s.substr(0, s.size() - 1)) {
            cur += c == '0' ? 1 : -1;
            ans = std::max(ans, cur);
        }
        return ans;
    }
};