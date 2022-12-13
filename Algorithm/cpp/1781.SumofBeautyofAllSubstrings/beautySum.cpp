class Solution {
public:
    int getBeauty(int count[26]) {
        int minFreq = 502, maxFreq = -1;
        for (int i = 0; i < 26; ++i) {
            if (!count[i]) continue;
            minFreq = std::min(minFreq, count[i]);
            maxFreq = std::max(maxFreq, count[i]);
        }
        return maxFreq - minFreq;
    }
    int beautySum(string s) {
        if (s.size() < 3) return 0;
        int n = s.size(), ans = 0;
        for (int len = 3; len <= n; ++len) {
            int count[26] = {};
            for (int i = 0; i < len; ++i) {
                ++count[s[i] - 'a'];
            }
            ans += getBeauty(count);
            for (int l = 0, r = len; r < n; ++l, ++r) {
                --count[s[l] - 'a'];
                ++count[s[r] - 'a'];
                ans += getBeauty(count);
            }
        }
        return ans;
    }
};