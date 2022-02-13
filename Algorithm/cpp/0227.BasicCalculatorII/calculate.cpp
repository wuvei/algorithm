class Solution {
public:
    inline int calc() {
        int n1 = num.top();
        num.pop();
        int n2 = num.top();
        num.pop();
        char op = ops.top();
        ops.pop();
        switch (op) {
            case '+':
                return n1 + n2;
            case '-':
                return n2 - n1;
            case '*':
                return n1 * n2;
            case '/':
                return n2 / n1;
        }
        return 1;
    }
    int calculate(string s) {
        stack<int>().swap(num);
        stack<char>().swap(ops);
        string a;
        for (char c: s) {
            if (c == ' ') continue;
            if (c >= '0' && c <= '9') a += c;
            else {
                num.push(std::stoi(a));
                a = "";
                while (!ops.empty() && pri[c] >= pri[ops.top()]) num.push(calc());
                ops.push(c);
            }
        }
        num.push(std::stoi(a));
        while (!ops.empty()) {
            num.push(calc());
        }
        return num.top();
    }
private:
    stack<int> num;
    stack<char> ops;
    unordered_map<char, int> pri = {{'*', 1}, {'/', 1}, {'+', 2}, {'-', 2}};
};


class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int curr = 0;
        char sign = '+';
        stack<int> st;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isdigit(c)) curr = curr * 10 + (c - '0');
            if ((!(c == ' ') and !isdigit(c)) or i == n - 1) {
                switch (sign) {
                    case '+':
                    case '-':
                        curr = (sign == '+') ? curr : -curr;
                        st.push(curr);
                        break;
                    case '*':
                    case '/':
                        int a = st.top();
                        st.pop();
                        a = (sign == '*') ? a * curr : a / curr;
                        st.push(a);
                }
                sign = c;
                curr = 0;
            }
        }
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};