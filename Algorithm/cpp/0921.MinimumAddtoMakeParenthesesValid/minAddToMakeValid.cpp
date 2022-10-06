class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0, ans = 0;
        for (char c: s) {
            c == '(' ? ++left : --left;
            if (left < 0) {
                left = 0;
                ++ans;
            }
        }
        return ans + left;
    }
};