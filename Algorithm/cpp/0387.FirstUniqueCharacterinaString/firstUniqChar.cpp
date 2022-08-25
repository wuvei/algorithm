class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> pos(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (pos[idx] == -1)
                pos[idx] = i;
            else
                pos[idx] = -2;
        }
        int early = s.size();
        for (int e: pos) {
            if (e >= 0 && early > e)
                early = e;
        }
        return (early == s.size()) ? -1 : early;
    }
};