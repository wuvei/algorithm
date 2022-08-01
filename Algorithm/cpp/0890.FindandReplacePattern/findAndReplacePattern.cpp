class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int pat[26] = {}, curr = 1, n = pattern.size();
        vector<int> code(n, 0);
        for (int i = 0; i < n; ++i) {
            int idx = pattern[i] - 'a';
            if (!pat[idx]) {
                pat[idx] = curr++;
            }
            code[i] = pat[idx];
        }
        vector<string> ans;
        for (auto &w: words) {
            curr = 1;
            memset(pat, 0, 26 * sizeof(int));
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                int idx = w[i] - 'a';
                if (!pat[idx])
                    pat[idx] = curr++;
                if (pat[idx] != code[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(w);
        }
        return ans;
    }
};