class Solution {
public:
    int secondHighest(string s) {
        int stat = 0;
        for (char c: s) {
            if (std::isdigit(c)) {
                stat |= (1 << (c - '0'));
            }
        }
        for (int i = 9, cnt = 0; i >= 0; --i) {
            if (stat & (1 << i)) {
                if (cnt == 1) return i;
                ++cnt;
            }
        }
        return -1;
    }
};