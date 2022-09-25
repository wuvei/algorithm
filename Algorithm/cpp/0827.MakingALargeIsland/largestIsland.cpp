class Djs {
public:
    std::vector<int> fa, size;
    Djs(){}
    Djs(int n): fa(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            fa[i] = i;
        }
    }
    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void connect(int x, int y) {
        int xx = find(x), yy = find(y);
        if (xx == yy) return;
        if (size[xx] > size[yy]) {
            swap(xx, yy);
        }
        fa[xx] = yy;
        size[yy] += size[xx];
    }
};
class Solution {
private:
    vector<vector<bool> > visit;
    Djs uf;
    const int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int n;
public:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        visit[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] && !visit[nx][ny]) {
                uf.connect(x * n + y, nx * n + ny);
                dfs(grid, nx, ny);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 1) {
            return 1;
        }
        uf = Djs(n * n);
        visit.resize(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && !visit[i][j]) {
                    dfs(grid, i, j);
                }
            }
        }
        
        int ans = *std::max_element(uf.size.begin(), uf.size.end());
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    continue;
                }
                unordered_set<int> s;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dir[k][0], ny = j + dir[k][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny]) {
                        s.insert(uf.find(nx * n + ny));
                    }
                }
                int temp = 0;
                for (int e: s) {
                    temp += uf.size[e];
                }
                ans = std::max(ans, temp + 1);
            }
        }
    return ans;
    }
};