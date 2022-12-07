class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        int l = -1, r = -1;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (std::isdigit(c)) {
                if (l == -1 || word[l] == '0') {
                    l = i;
                }
                r = i;
            }
            else if (l != -1) {
                s.insert(word.substr(l, r - l + 1));
                l = -1;
            }
        }
        if (l != -1) {
            s.insert(word.substr(l));
        }
        return s.size();
    }
};