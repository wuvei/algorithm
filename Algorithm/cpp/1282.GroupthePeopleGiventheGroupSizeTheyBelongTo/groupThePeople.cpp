class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int> > m;
        for (int i = 0; i < groupSizes.size(); ++i) {
            m[groupSizes[i]].push_back(i);
        }
        vector<vector<int> > ans;
        for (auto it: m) {
            auto &[len, v] = it;
            for (int i = 0; i < v.size() / len; ++i) {
                vector<int> temp(len);
                for (int j = i * len, k = 0; k < len; ++k) {
                    temp[k] = v[j + k];
                }
                ans.push_back(move(temp));
            }
        }
        return ans;
    }
};