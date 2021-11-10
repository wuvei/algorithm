class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        stack<char> st;
        int count = 0;
        for (char c: num) {
            while (!st.empty() && k && st.top() > c) {
                st.pop();
                k--;
            }
            if(st.empty() && c== '0')
                continue;
            st.push(c);
        }
        while(k && !st.empty()) {
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        if (ans == "") return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};