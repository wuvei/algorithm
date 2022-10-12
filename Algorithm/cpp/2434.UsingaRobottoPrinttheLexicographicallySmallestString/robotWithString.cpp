class Solution {
public:
    string robotWithString(string s) {
        int cnt[26]{}, first = 0;
        stack<char> st;
        for (char c: s) {
            ++cnt[c - 'a'];
        }
        string ans;
        ans.reserve(s.size());
        for (char c: s) {
            --cnt[c - 'a'];
            while (first < 25 && !cnt[first]) {
                ++first;
            }
            st.push(c);
            while (!st.empty() && st.top() - 'a' <= first) {
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};