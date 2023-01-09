class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0, len = pref.size();
        for (string &w: words) {
            if (w.size() < len) continue;
            bool flag = true;
            for (int i = 0; i < len && flag; ++i) {
                if (w[i] != pref[i])
                    flag = false;
            }
            if (flag) ++ans;
        }
        return ans;
    }
};