class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        ans.reserve(n);
        int l = 0, r = k + 2;
        while ((++l) < (--r)) {
            ans.push_back(l);
            ans.push_back(r);
        }
        if (l == r) {
            ans.push_back(l);
        }
        for (int i = k + 2; i <= n; ++i) {
            ans.push_back(i);
        }
        return ans;
    }
};