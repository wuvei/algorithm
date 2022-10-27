class StockSpanner {
public:
    StockSpanner() {
        st = {};
        idx = 0;
    }
    
    int next(int price) {
        while (!st.empty() && st.top().second <= price) {
            st.pop();
        }
        int ans = st.empty() ? idx + 1 : idx - st.top().first;
        st.push({idx, price});
        ++idx;
        return ans;
    }
private:
    stack<pair<int, int> > st;
    int idx;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */