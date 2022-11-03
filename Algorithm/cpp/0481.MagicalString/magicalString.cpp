class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) return 1;
        int ans = 1, t = 1;
        string s(n + 4, ' ');
        s[0] = '1'; s[1] = s[2] = '2';
        for (int i = 2, j = 3; j < n; ++i) {
            for (int k = 0; k < s[i] - '0' && j < n; ++k, ++j) {
                s[j] = t + '0';
                if (t == 1 && j < n)
                    ++ans;
            }
            t = 3 - t;
        }
        return ans;
    }
};