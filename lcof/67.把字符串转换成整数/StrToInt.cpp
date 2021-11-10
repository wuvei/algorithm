class Solution {
public:
    int strToInt(string str) {
        int length = str.size();
        if (!length) return 0;
        int pt = 0;
        for (; pt < length; pt++) {
            char ch = str[pt];
            if (ch == ' ') continue;
            else if (ch == '+' || ch == '-' || (ch <= '9' && ch >= '0')) break;
            else return 0;
        }
            
        int val = 0;
        bool negative = str[pt] == '-';
        if (str[pt] <= '9' && str[pt] >= '0') val = int(str[pt] - '0');

        while (isdigit(str[++pt])) {
            //判断是否溢出
            if (val > INT_MAX / 10 || (val == INT_MAX / 10 && str[pt] - '0' > 7)) {
                if (negative)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            val = val * 10 + (str[pt] - '0');
        }
        return negative ? -val : val;
    }
};