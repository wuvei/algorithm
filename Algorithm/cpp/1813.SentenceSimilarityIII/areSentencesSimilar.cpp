class Solution {
public:
    vector<string> split(string &s) {
        std::stringstream ss(s);
        string temp;
        vector<string> ans;
        while (ss >> temp) {
            ans.push_back(std::move(temp));
        }
        return std::move(ans);
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> v1 = split(sentence1), v2 = split(sentence2);
        if (v1.size() > v2.size())
            std::swap(v1, v2);
        int prefix = 0, len1 = v1.size(), len2 = v2.size();
        for (int i = 0; i < len1 && v1[i] == v2[i]; ++i, ++prefix);
        if (prefix == len1) return true;
        int suffix = 0;
        for (int i1 = len1 - 1, i2 = len2 - 1; i1 >= 0 && v1[i1] == v2[i2]; --i1, --i2, ++suffix);
        if (prefix + suffix >= len1) return true;
        return false;
    }
};