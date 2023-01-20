class Solution {
public:
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
        int n = vals.size();
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        // 并查集模板
        // size[x] 表示节点值等于 vals[x] 的节点个数，如果按照节点值从小到大合并，size[x] 也是连通块内的等于最大节点值的节点个数
        int id[n], fa[n], size[n]; // id 后面排序用
        iota(id, id + n, 0);
        iota(fa, fa + n, 0);
        fill(size, size + n, 1);
        std::function<int(int)> find = [&](int x) -> int { 
            return fa[x] == x ? x : fa[x] = find(fa[x]);
        };

        int ans = n;
        sort(id, id + n, [&](int i, int j) { return vals[i] < vals[j]; });
        for (int x : id) {
            int vx = vals[x], fx = find(x);
            for (int y : g[x]) {
                y = find(y);
                if (y == fx || vals[y] > vx) continue; // 只考虑最大节点值比 vx 小的连通块
                if (vals[y] == vx) { // 可以构成好路径
                    ans += size[fx] * size[y]; // 乘法原理
                    size[fx] += size[y]; // 统计连通块内节点值等于 vx 的节点个数
                }
                fa[y] = fx; // 把小的节点值合并到大的节点值上
            }
        }
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/number-of-good-paths/solutions/1847967/bing-cha-ji-by-endlesscheng-tbz8/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。