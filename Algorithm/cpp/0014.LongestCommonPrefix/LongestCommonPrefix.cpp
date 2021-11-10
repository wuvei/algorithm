class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        if (!strs.size() || !strs[0].size()) return s;
        int idx = 0, nums = strs.size();
        bool flag = true;
        while(flag) {
            if (idx >= strs[0].size()) {
                flag = false;
                break;
            }
            char ch = strs[0][idx];
            for (int i = 1; i < nums; i++) {
                if (idx >= strs[i].size() || ch != strs[i][idx]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                s += ch;
                idx++;
            }
        }
        return s;
    }
};