class Solution {
public:
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0] - 1, y = e[1] - 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int time[n], clock = 0; // time 充当 vis 数组的作用（避免在 BFS 内部重复创建 vis 数组
        memset(time, 0, sizeof(time));
        auto bfs = [&](int start) -> int {
            int depth = 0;
            time[start] = ++clock;
            vector<int> q = {start};
            while (!q.empty()) {
                vector<int> nxt;
                for (int x : q)
                    for (int y : g[x])
                        if (time[y] != clock) { // 没有在同一次 BFS 中访问过
                            time[y] = clock;
                            nxt.push_back(y);
                        }
                q = move(nxt);
                ++depth;
            }
            return depth;
        };

        int8_t color[n]; memset(color, 0, sizeof(color));
        vector<int> nodes;
        function<bool(int, int8_t)> is_bipartite = [&](int x, int8_t c) -> bool {
            nodes.push_back(x);
            color[x] = c;
            for (int y : g[x])
                if (color[y] == c || color[y] == 0 && !is_bipartite(y, -c))
                    return false;
            return true;
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (color[i]) continue;
            nodes.clear();
            if (!is_bipartite(i, 1)) return -1; 
            int max_depth = 0;
            for (int x : nodes)
                max_depth = max(max_depth, bfs(x));
            ans += max_depth;
        }
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/divide-nodes-into-the-maximum-number-of-groups/solutions/2005131/mei-ju-qi-dian-pao-bfs-by-endlesscheng-s5bu/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。