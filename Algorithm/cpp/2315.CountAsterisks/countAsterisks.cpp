class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        bool flag = true;
        for (char c: s) {
            if (c == '|') flag = !flag;
            else if (c == '*' && flag) ++ans;
        }
        return ans;
    }
};