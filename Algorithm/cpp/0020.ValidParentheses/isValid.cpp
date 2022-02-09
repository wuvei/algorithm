class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
        unordered_set<char> pre = {'(', '[', '{'};
        stack<char> st;
        for (char c: s) {
            if (pre.find(c) != pre.end())
                st.push(c);
            else {
                if (st.empty() || st.top() != m[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};