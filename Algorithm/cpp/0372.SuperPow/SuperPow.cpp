class Solution {
public:
    int binpow(int a, int b) {
        a %= 1337;
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % 1337;
            a = a * a % 1337;
            b >>= 1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        if (a == 1 || b.size() == 0) return 1;
        int ans = 1;
        for(int i = b.size() - 1; i >= 0; i--) {
            ans = binpow(a, b[i]) * ans % 1337;
            a = binpow(a, 10);
        }
        return ans;
    }
};