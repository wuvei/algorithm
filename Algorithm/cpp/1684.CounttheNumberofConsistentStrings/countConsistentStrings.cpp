class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt[26] = {}, ans = 0;
        for (char c: allowed) {
            ++cnt[c - 'a'];
        }
        for (string &s: words) {
            bool flag = true;
            for (char c: s) {
                if (!cnt[c - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) ++ans;
        }
        return ans;
    }
};