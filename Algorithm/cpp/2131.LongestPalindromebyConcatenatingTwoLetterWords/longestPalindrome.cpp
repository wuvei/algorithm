class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> cnt, cnt2;
        string s(2, ' ');
        for (auto &w: words) {
            if (w[0] == w[1]) {
                ++cnt2[w];
                continue;
            }
            s[0] = w[1];
            s[1] = w[0];
            if (cnt[s]) {
                --cnt[s];
                ans += 4;
            }
            else ++cnt[w];
        }
        bool flag = true;
        for (auto &it: cnt2) {
            if ((it.second & 1) && flag) {
                --it.second;
                flag = false;
                ans += 2;
            }
            ans += (it.second >> 1) << 2;
        }
        return ans;
    }
};

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int cnt[26][26] = {};
        for (auto &w: words)
            ++cnt[w[0] - 'a'][w[1] - 'a'];
        int ans = 0, odd = 0; // 是否有一个出现奇数次的 AA
	    for (int i = 0; i < 26; ++i) {
            int c = cnt[i][i]; // 相同字符
            ans += c & ~1;  // 等价于 c - c % 2
            odd |= c & 1;
            for (int j = i + 1; j < 26; ++j) {
                ans += min(cnt[i][j], cnt[j][i]) << 1; // AB BA 取出现次数最小值
            }
        }
	    return (ans + odd) << 1; // 上面的循环统计的是字符串个数，最后再乘 2
    }
};
