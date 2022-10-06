class Solution {
public:
    string reformatNumber(string number) {
        string ans;
        int n = number.size(), count = 0;
        ans.reserve(n << 1);
        for (int i = 0; i < n; ++i) {
            if (isdigit(number[i])) {
                ++count;
            }
        }
        int i = 0, group = 3;
        while (i < n) {
            if (count == 4) {
                group = 2;
            }
            for (int j = 0; i < n && j < group; ++i) {
                if (!isdigit(number[i])) {
                    continue;
                }
                ans += number[i];
                ++j;
                --count;
            }
            if (i < n && count) {
                ans += '-';
            }
        }
        return ans;
    }
};