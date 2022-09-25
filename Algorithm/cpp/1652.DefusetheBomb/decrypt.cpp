class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if (k == 0) {
            return vector<int>(n, 0);
        }
        vector<int> ans(n);
        int l, r;
        if (k > 0) {
            l = 1;
            r = k;
        }
        else {
            l = n + k;
            r = n - 1;
        }
        int sum = std::accumulate(code.begin() + l, code.begin() + r + 1, 0);
        ans[0] = sum;
        for (int i = 1; i < n; ++i) {
            sum -= code[l];
            l = (l == n - 1) ? 0 : l + 1;
            r = (r == n - 1) ? 0 : r + 1;
            sum += code[r];
            ans[i] = sum;
        }
        return ans;
    }
};