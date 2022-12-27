class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0, prev = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'X' && prev == -1)
                prev = i;
            if (prev != -1 && i - prev == 2) {
                ++ans;
                prev = -1;
            }
        }
        if (prev != -1) ++ans;
        return ans;
    }
};