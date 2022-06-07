// BFS
class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int m, n;
    vector<vector<int>> f;

    int bfs(pair<int, int>& s, pair<int, int>& e) {
        if (s.first == e.first && s.second == e.second) return 0;

        queue<pair<int, int>> q;
        q.push(s);

        int step = 0;
        bool vis[m][n];
        memset(vis, 0, sizeof(vis));
        vis[s.first][s.second] = 1;

        while (!q.empty()) {
            step++;
            int size = q.size();
            
            while(size--) {
                pair<int, int> p = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int x = p.first + dx[d];
                    int y = p.second + dy[d];
                    
                    if (x < 0 || y < 0 || x >= m || y >= n) continue;
                    if (f[x][y] == 0) continue;
                    if (vis[x][y]) continue;
                    if (x == e.first && y == e.second) return step;

                    vis[x][y] = 1;
                    q.push(make_pair(x, y));
                }
            }
            
        }        

        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        this->f = forest;
        m = f.size();
        n = f[0].size();

        if (f[0][0] == 0) return -1;

        vector<pair<int, pair<int, int>>> h;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (f[i][j] > 1) {
                    h.push_back(make_pair(f[i][j], make_pair(i, j)));
                }
            }
        }

        sort(h.begin(), h.end());
        pair<int, int> s = {0, 0};
        int distance = 0;

        for (auto &p: h) {
            int d = bfs(s, p.second);
            if (d == -1) return -1;
            distance += d;
            s = p.second;
        }

        return distance;
    }
};