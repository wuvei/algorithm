class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans({{1}});
        for (int i = 2; i <= numRows; ++i) {
            vector<int> row(i, 1), &prev = ans.back();
            for (int j = 1; j < i - 1; ++j)
                row[j] = prev[j - 1] + prev[j];
            ans.push_back(std::move(row));
        }
        return ans;
    }
};