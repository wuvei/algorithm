class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool flag = true;
        int idx = 0, sign = 1;
        while (s[idx] == ' ') ++idx;
        if (s[idx] == '-') {
            sign = -1;
            ++idx;
        }
        else if (s[idx] == '+')
            ++idx;
        while (idx < s.size() && isdigit(s[idx])) {
            ans = ans * 10 + s[idx] - '0';
            if (ans * sign < INT_MIN) return INT_MIN;
            else if (ans * sign > INT_MAX) return INT_MAX;
            ++idx;
        }
        return static_cast<int>(ans * sign);
    }
};