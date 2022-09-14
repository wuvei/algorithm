class Solution {
public:
    int maximumSwap(int num) {
        string s = std::to_string(num);
        vector<int> maxIdx(s.size());
        maxIdx[s.size() - 1] = s.size() - 1;
        for (int i = s.size() - 2; i >= 0; --i) {
            maxIdx[i] = (s[i] > s[maxIdx[i + 1]]) ? i: maxIdx[i + 1];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != s[maxIdx[i]]) {
                swap(s[i], s[maxIdx[i]]);
                break;
            }
        }
        return std::stoi(s);
    }
};