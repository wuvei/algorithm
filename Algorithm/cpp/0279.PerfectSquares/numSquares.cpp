// math
class Solution {
public:
    int numSquares(int n) {
        int sq = sqrt(n);
        if(sq*sq == n) // Perfect Square case
            return 1;

        while(n%4 == 0) // Removing the 4^a term
            n = n/4;

        if(n%8 == 7) // Check if no is of the form 8b+7
            return 4;

        for(int i=1; i*i <= n; i++){
            int base = sqrt(n - i*i);
            if(base*base == n-i*i) // Check single breakpoint for two squares
                return 2;
        }
        return 3;
    }
};

// DP
class Solution {
public:
    int numSquares(int n) {
        if (n < 4) return n;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 3;
        dp[4] = 1;
        for (int i = 5; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};