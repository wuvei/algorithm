class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string m[26] = {};
        istringstream in(s);
        string t;
        int idx = 0;
        unordered_set<string> count;
        while (in >> t) {
            if (idx >= pattern.size())
                return false;
            int c = pattern[idx] - 'a';
            if (m[c] == "") {
                if (count.find(t) != count.end()) return false;
                m[c] = t;
                count.emplace(t);
            }
            else if (m[c] != t)
                return false;
            ++idx;
        }
        return idx == pattern.size();
    }
};