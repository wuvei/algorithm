// Disjoint Union Set
class Solution {
public:
    class DJU {
    private:
        vector<int> parent, rank;
    public:
        DJU (int n): rank(vector<int>(n, 1)), parent(vector<int>(n)) {
            for (int i = 0; i < n; ++i)
                parent[i] = i;
        }
        int find(int x) {
            if (x != parent[x])
                parent[x] = find(parent[x]);
            return parent[x];
        }
        void connect(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return;
            if (rank[x] < rank[y]) swap(x, y);
            parent[y] = x;
            rank[x] += rank[y];
        }
        bool if_connect(int x, int y) {
            return find(x) == find(y);
        }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int> > edges;
        int m = heights.size(), n = heights[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < m - 1) edges.push_back({abs(heights[i][j] - heights[i + 1][j]), i, j, i + 1, j});
                if (j < n - 1) edges.push_back({abs(heights[i][j] - heights[i][j + 1]), i, j, i, j + 1});
            }
        }
        DJU uf(m * n);
        sort(edges.begin(), edges.end());
        int ans = 0, start = 0, end = m * n - 1;
        for (auto &v: edges) {
            uf.connect(v[1] * n + v[2], v[3] * n + v[4]);
            if (uf.if_connect(start, end)) {
                ans = v[0];
                break;
            }
        }
        return ans;
    }
};

// Binary Search
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size(), \
        left = 0, right = 999999, ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            queue<pair<int, int> > q;
            q.emplace(0, 0);
            vector<int> seen(m * n);
            seen[0] = 1;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dirs[i][0];
                    int ny = y + dirs[i][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny] && abs(heights[x][y] - heights[nx][ny]) <= mid) {
                        q.emplace(nx, ny);
                        seen[nx * n + ny] = 1;
                    }
                }
            }
            if (seen[m * n - 1]) {
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};

// 作者：zerotrac2
// 链接：https://leetcode-cn.com/problems/path-with-minimum-effort/solution/zui-xiao-ti-li-xiao-hao-lu-jing-by-zerotrac2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。