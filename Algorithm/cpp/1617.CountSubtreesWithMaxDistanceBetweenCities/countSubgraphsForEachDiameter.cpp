class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges) {
        vector<vector<int>> g(n);
        // build graph / tree
        for (auto &e : edges) {
            int x = e[0] - 1, y = e[1] - 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> ans(n - 1);
        int mask = 3, vis = 0, diameter = 0;
        function<int(int)> dfs = [&](int x) -> int {
            vis |= 1 << x;
            int max_len = 0;
            for (int y : g[x])
                if ((vis >> y & 1) == 0 && mask >> y & 1) {
                    int ml = dfs(y) + 1;
                    diameter = max(diameter, max_len + ml);
                    max_len = max(max_len, ml);
                }
            return max_len;
        };
        for (; mask < 1 << n; ++mask) {
            if ((mask & (mask - 1)) == 0) continue; // only 1 point
            // calculate diameter
            vis = 0, diameter = 0;
            dfs(__builtin_ctz(mask)); // 从一个在 mask 中的点开始递归
            if (vis == mask)
                ++ans[diameter - 1];
        }
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/count-subtrees-with-max-distance-between-cities/solutions/2162612/tu-jie-on3-mei-ju-zhi-jing-duan-dian-che-am2n/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。