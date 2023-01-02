class Solution {
    using pqii = priority_queue<pair<int,int>>;
    const int mod = 1e9 + 7;
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        long long ans = 0;
        pqii buy, sell; //通过价格取负模拟小根堆
        for (vector<int>& o : orders) {
            if (o[2] == 0) solve(sell, buy, o, true);
            else solve(buy, sell, o, false);
        }
        while (!buy.empty()) ans += buy.top().second, buy.pop();
        while (!sell.empty()) ans += sell.top().second, sell.pop();
        return static_cast<int>(ans % mod);
    }
    void solve(pqii& q1, pqii& q2, vector<int>& o, bool ok) {
        while (!q1.empty() && o[1] != 0 && (ok ? -q1.top().first <= o[0] : q1.top().first >= o[0])) {
            auto t = q1.top(); q1.pop();
            int cnt = min(o[1], t.second);
            o[1] -= cnt;
            t.second -= cnt;
            if (t.second > 0) q1.push(t);
        }
        if (o[1] > 0) q2.push({ok ? o[0] : -o[0], o[1]}); 
    }
}; 

// 作者：Tizzi
// 链接：https://leetcode.cn/problems/number-of-orders-in-the-backlog/solutions/2041070/javac-you-xian-dui-lie-mo-ni-by-tizzi-4dwu/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。