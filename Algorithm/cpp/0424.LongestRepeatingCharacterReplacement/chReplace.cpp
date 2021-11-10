class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26, 0);
        int l = 0, len = s.size(), ans = 0, cur_max = 0;
        for(int i = 0; i < len; i++) {
            v[s[i] - 'A']++;
            cur_max = std::max(cur_max, v[s[i] - 'A']);
            if (i - l + 1 - cur_max > k) {
                v[s[l++] - 'A']--;
            }
            ans = std::max(ans, i - l + 1);
        }
        return ans;
    }
};