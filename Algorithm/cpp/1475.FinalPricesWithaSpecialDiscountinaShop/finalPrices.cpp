class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        vector<int> ans(prices);
        for (int i = prices.size() - 1; i >= 0; --i) {
            int p = prices[i];
            while (!st.empty() && st.top() > p)
                st.pop();
            if (!st.empty())
                ans[i] -= st.top();
            st.push(p);
        }
        return ans;
    }
};