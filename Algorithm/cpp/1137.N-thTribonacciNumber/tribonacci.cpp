class Solution {
public:
    int tribonacci(int n) {
        if (n < 3) {
            if (n == 0) return 0;
            return 1;
        }
        vector<int> d(n + 1, 0);
        d[1] = d[2] = 1;
        for (int i = 3; i <= n; ++i) {
            d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        }
        return d[n];
    }
};