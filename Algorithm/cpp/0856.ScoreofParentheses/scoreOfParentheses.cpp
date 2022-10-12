class Solution {
public:
    inline int get(char c) {
        return (c == '(') ? -1 : -2;
    }
    int scoreOfParentheses(string s) {
        stack<int> st;
        for (char c: s) {
            if (get(c) == -1) {
                st.push(-1);
            }
            else {
                int t = 0;
                while (st.top() != -1) {
                    t += st.top();
                    st.pop();
                }
                st.pop();
                if (t) {
                    st.push(2 * t);
                }
                else {
                    st.push(1);
                }
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};


// depth and contriutions of "()"
class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, d = 0;
        for(int i = 0; i < s.size(); ++i) {
            d += s[i] == '(' ? 1 : -1;
            if(s[i] == ')' && s[i - 1] == '(') {
                ans += 1 << d;
            }
        }
        return ans;
    }
};
