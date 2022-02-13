class Solution {
public:
    /**
     * @param s: the expression string
     * @return: the answer
     */
    using ll = long long;

    inline void calc() {
        ll n1 = vals.top();
        vals.pop();
        ll n2 = vals.top();
        vals.pop();
        char op = ops.top();
        ops.pop();
        switch(op) {
            case '+':
                vals.push(n1 + n2);
                break;
            case '-':
                vals.push(n2 - n1);
                break;
            case '*':
                vals.push(n1 * n2);
                break;
            case '/':
                vals.push(n2 / n1);
                break;
        }
    }
    int calculate(string &s) {
        stack<ll>().swap(vals);
        stack<char>().swap(ops);
        string num;
        for (char c: s) {
            if (std::isdigit(c)) num += c;
            else {
                if (num != "") vals.push(std::stoll(num));
                num = "";
                if (c == ' ') continue;
                if (c == '(') ops.push(c);
                else if (c == ')') {
                    while (!ops.empty() && ops.top() != '(') {
                        calc();
                    }
                    ops.pop();
                }
                else { // op = +,-,*,/
                    while (!ops.empty() && ops.top() != '(' && priority[c] >= priority[ops.top()] ) {
                        calc();
                    }
                    ops.push(c);
                }
            }
        }
        if (num != "") vals.push(std::stoll(num));
        while (!ops.empty()) {
            calc();
        }
        return int(vals.top());
    }
private:
    stack<ll> vals;
    stack<char> ops;
    unordered_map<char, int> priority = {{'+', 2}, {'-', 2}, {'*', 1}, {'/', 1}};
};