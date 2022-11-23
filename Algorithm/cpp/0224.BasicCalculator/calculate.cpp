class Solution {
public:
    void calc(stack<int> &num, stack<char> &ops) {
        char c = ops.top();
        ops.pop();
        int n1 = num.top();
        num.pop();
        int n2 = num.top();
        num.pop();
        if (c == '-') num.push(n2 - n1);
        else num.push(n2 + n1);
    }
    int calculate(string s) {
        stack<int> num;
        stack<char> ops;
        int d = 0;
        char prev = '#';
        for (char c: s) {
            if (c == ' ')
                continue;
            if (std::isdigit(c)) {
                d = d * 10 + static_cast<int>(c - '0');
            }
            else {
                if (std::isdigit(prev)) {
                    num.push(d);
                }
                d = 0;
                if (c == ')') {
                    while (ops.top() != '(') {
                        calc(num, ops);
                    }
                    ops.pop();
                }
                else if (c == '(') {
                    ops.push(c);
                }
                else { // + -
                    if (prev == '#' || prev == '(')
                        num.push(0);
                    if (!ops.empty() && (ops.top() == '-' || ops.top() == '+'))
                        calc(num, ops);
                    ops.push(c);
                }
            }
            prev = c;
        }
        if (std::isdigit(prev)) num.push(d);
        while (!ops.empty()) {
            calc(num, ops);
        }
        return num.top();
    }
};