class Solution {
public:
    string reorderSpaces(string text) {
        int count = 0;
        for (char c: text) {
            if (c == ' ') {
                ++count;
            }
        }
        
        vector<string> v;
        istringstream is(text);
        string word;
        while (is >> word) {
            v.push_back(word);
        }

        int between = (v.size() == 1) ? 0 : count / (v.size() - 1), left = count - between * (v.size() - 1);
        word = std::move(v[0]);
        for (int i = 1; i < v.size(); ++i) {
            word += std::move(string(between, ' '));
            word += std::move(v[i]);
        }
        word += std::move(string(left, ' '));
        return word;
    }
};