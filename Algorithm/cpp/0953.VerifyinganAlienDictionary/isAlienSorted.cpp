class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int seq[26]{};
        for (int i = 0; i < order.size(); ++i)
            seq[order[i] - 'a'] = i;
        for (int i = 0; i < words.size() - 1; ++i) {
            int j = 0;
            auto &s1 = words[i], &s2 = words[i + 1];
            for (; j < s1.size() && j < s2.size(); ++j) {
                if (seq[s1[j] - 'a'] > seq[s2[j] - 'a'])
                    return false;
                else if (seq[s1[j] - 'a'] < seq[s2[j] - 'a'])
                    break;
            }
            if ((j == s1.size() || j == s2.size()) && s1.size() > s2.size())
                return false;
        }
        return true;
    }
};