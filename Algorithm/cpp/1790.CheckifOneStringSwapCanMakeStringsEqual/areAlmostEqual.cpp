class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0, idx[2]{};
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i])
                continue;
            if (cnt == 2) return false;
            idx[cnt] = i;
            ++cnt;
        }
        if (cnt == 1) return false;
        return cnt == 0 || (s1[idx[0]] == s2[idx[1]] && s1[idx[1]] == s2[idx[0]]);
    }
};