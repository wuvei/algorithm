class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        bool ht = false, hf = false;
        for (char c: expression) {
            ht = false;
            hf = false;
            if (c == ')') {
                while (st.top() != '(') {
                    if (st.top() == 't') ht = true;
                    else if (st.top() == 'f') hf = true;
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                switch (op) {a
                    case '&': {
                        if (hf) st.push('f');
                        else st.push('t');
                        break;
                    }
                    case '|': {
                        if (ht) st.push('t');
                        else st.push('f');
                        break;
                    }
                    case '!': {
                        if (ht) st.push('f');
                        else st.push('t');
                        break;
                    }
                    default:
                        break;
                }
            }
            else if (c != ',') {
                st.push(c);
            }
        }
        return st.top() == 'f' ? false : true;
    }
};