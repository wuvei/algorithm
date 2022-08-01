class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> code(26, 0);
        for (auto &s: words2) {
            vector<int> count(26, 0);
            for (char c: s)
                ++count[c - 'a'];
            
            for (int i = 0; i < 26; ++i)
                if (code[i] < count[i])
                    code[i] = count[i];
        }
        vector<string> ans;
        for (auto &s: words1) {
            vector<int> count(26, 0);
            for (char c: s) {
                ++count[c - 'a'];
            }
            int i = 0;
            for (; i < 26; ++i)
                if (code[i] > count[i])
                    break;
            if (i == 26)
                ans.push_back(s);
        }
        return ans;
    }
};