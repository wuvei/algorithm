class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.size() == 1) return 0;
        int ans = 0, n = strs.size(), len = strs[0].size();
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j][i] < strs[j - 1][i]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};