class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) continue;
            if (s1[i] == 'x' && s2[i] == 'y')
                ++xy;
            else ++yx;
        }
        if ((xy + yx) & 1) return -1;
        return (xy >> 1) + (yx >> 1) + ((xy & 1) << 1);
    }
};