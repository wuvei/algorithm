class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        int max_count = 0;
        for (char c: s) max_count = std::max(max_count, ++count[c]);
        vector<vector<char> > order(max_count + 1);
        for (auto it: count) order[it.second].push_back(it.first);
        string ans;
        for (int i = max_count; i > 0; --i) {
            for (char c: order[i]) ans += std::string(count[c], c);
        }
        return ans;
    }
};