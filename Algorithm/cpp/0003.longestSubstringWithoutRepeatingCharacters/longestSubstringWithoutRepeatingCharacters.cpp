class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256] = {0}, res = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 0 || m[s[i]] < left) {
                res = max(res, i - left + 1);
            } else {
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, ans = 0;
        unordered_map<char, int> count;
        for (; r < s.size(); r++) {
            char c = s[r];
            count[c]++;
            while (count[c] > 1) {
                count[s[l]]--;
                l++;
            }
            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }
};