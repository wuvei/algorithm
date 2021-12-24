class Solution {
private:
    int dir[5] = {1, 0, -1, 0, 1};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool> > ifPac(m, vector<bool>(n,  false)), ifAtl(ifPac);
        bfs(heights, ifPac, true);
        bfs(heights, ifAtl, false);
        vector<vector<int> > ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (ifPac[i][j] && ifAtl[i][j]) ans.push_back({i, j});
        }
        return ans;
    }

    void initPac(vector<vector<bool> > &ifMat, vector<vector<bool> > &visited, queue<pair<int, int> > &q)  {
        for (int i = 0; i < ifMat[0].size(); i++) {
            ifMat[0][i] = true;
            visited[0][i] = true;
            q.push({0, i});
        }
        for (int i = 1; i < ifMat.size(); i++) {
            ifMat[i][0] = true;
            visited[i][0] = true;
            q.push({i, 0});
        }

    }
    void initAlt(vector<vector<bool> > &ifMat, vector<vector<bool> > &visited, queue<pair<int, int> > &q)  {
        int m = ifMat.size() - 1, n = ifMat[0].size() - 1;
        for (int i = 0; i <= n; i++) {
            ifMat[m][i] = true;
            visited[m][i] = true;
            q.push({m, i});
        }
        for (int i = 0; i < m; i++) {
            ifMat[i][n] = true;
            visited[i][n] = true;
            q.push({i, n});
        }
    }

    void bfs(vector<vector<int>>& heights, vector<vector<bool> > &ifMat, bool ifPac) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n,  false));
        queue<pair<int, int> > q;
        if (ifPac) initPac(ifMat, visited, q);
        else initAlt(ifMat, visited, q);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int r = p.first, c = p.second;
            for (int i = 0; i < 4; ++i) {
                int x = r + dir[i], y = c + dir[i+1];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && heights[r][c] <= heights[x][y]) {
                    q.push({x, y});
                    visited[x][y] = true;
                    ifMat[x][y] = true;
                }
            }

        }
    }
};