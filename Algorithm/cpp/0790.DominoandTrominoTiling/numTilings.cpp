class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int numTilings(int n) {
        int sum = 2, curr;  // vector<int> dp(n+1);
        int prev = 1, prev2 = 0;
        for (int i=1; i<=n; i++){
            
            curr = 0;
            // Dominos between pair of triminos
            curr = (0LL + curr + sum) % MOD;
            // one vertical domino
            curr = (curr - prev + MOD) % MOD;
            // two horizontal domino
            curr = (curr - prev2 + MOD) % MOD;
            
            sum = (0LL + sum + 2*curr) % MOD;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};