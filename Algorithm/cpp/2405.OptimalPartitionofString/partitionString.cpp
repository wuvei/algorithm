class Solution {
public:
    int partitionString(string s) {
        unsigned int count = 0;
        int ans = 1;
        for (char c: s) {
            if (count & (1 << (c - 'a'))) {
                ++ans;
                count = 0;
            }
            
            count |= (1 << (c - 'a'));
        }
        return ans;
    }
};