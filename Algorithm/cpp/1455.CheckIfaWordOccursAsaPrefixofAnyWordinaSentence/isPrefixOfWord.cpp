class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream is(sentence);
        string s;
        int n = searchWord.size(), idx = 1;
        auto f = [&](string &s) -> bool {
            for (int i = 0; i < n; ++i) {
                if (s[i] != searchWord[i])
                    return false;
            }
            return true;
        };
        while(is >> s) {
            if (f(s))
                return idx;
            ++idx;
        }
        return -1;
    }
};