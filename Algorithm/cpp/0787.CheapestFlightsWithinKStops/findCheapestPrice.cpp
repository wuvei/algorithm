class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n, 0x3f3f3f3f);
        dp[src] = 0;
        while(1+k--){
            vector<int> next = dp;
            for(auto& x: flights) next[x[1]] = min(next[x[1]], dp[x[0]] + x[2]);
            dp = move(next);
        }
        return dp[dst] == 0x3f3f3f3f ? -1 : dp[dst];
    }
};

// SPFA
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n, 0x3f3f3f3f);
        vector<vector<int> > e(n);
        queue<int> q;
        int sq;

        for(auto& x: flights) e[x[0]].push_back((x[1] << 16) + x[2]);
        dp[src] = 0;
        q.push(src);
        while(1+k-- && (sq = q.size())){
            vector<bool> vis(n);
            vector<int> cpy = dp;
            while(sq--){
                int now = q.front();
                for(auto x: e[now]){
                    int next = x>>16, v = x&0xffff;
                    cpy[next] = std::min(cpy[next], dp[now] + v);
                    if(vis[next]) continue;
                    vis[next] = 1;
                    q.push(next);
                }
                q.pop();
            }
            dp = move(cpy);
        }
        return dp[dst] == 0x3f3f3f3f ? -1 : dp[dst];
    }
};

// 作者：MuriyaTensei
// 链接：https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/solution/c-liang-chong-fang-fa-dong-tai-gui-hua-b-q8xe/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。