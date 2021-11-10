class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> cache(len + 1, false);
        cache[len] = true;
        for (int i = len - 1; i >= 0; i--) {
            string sub;
            for (int j = i; j < len; j++) {
                sub += s[j];
                if (cache[j + 1] && find(wordDict.begin(), wordDict.end(), sub) != wordDict.end()) {
                    cache[i] = true;
                    break;
                }
            }
        }
        return cache[0];
    }
};