class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char c: n) {
            int e = c - '0';
            if (e == 9) return 9;
            if (e > ans)
                ans = e;
        }
        return ans;
    }
};