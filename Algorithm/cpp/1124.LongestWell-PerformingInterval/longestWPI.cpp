class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size(), ans = 0;
        vector<int> prefix(n + 1);
        stack<int> st;
        st.push(prefix[0] = 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
            if (prefix[i] < prefix[st.top()]) st.push(i);
        }
        for (int i = n; i; --i) {
            while (!st.empty() && prefix[i] > prefix[st.top()]) {
                ans = std::max(ans, i - st.top());
                st.pop();
            }
        }
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/longest-well-performing-interval/solutions/2110211/liang-chong-zuo-fa-liang-zhang-tu-miao-d-hysl/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。