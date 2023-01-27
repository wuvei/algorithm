class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> t;
        t.reserve(n);
        vector<vector<string>> ans;
        function<bool(int, int)> check = [&](int l, int r) -> bool {
            while (l < r) {
                if (s[l++] != s[r--]) return false;
            }
            return true;
        };
        function<void(int)> f = [&](int start) {
            if (start == n) {
                ans.push_back(t);
                return;
            }
            for (int i = start; i < n; ++i) {
                if (check(start, i)) {
                    t.push_back(s.substr(start, i - start + 1));
                    f(i + 1);
                    t.pop_back();
                }
            }
        };
        f(0);
        return ans;
    }
};