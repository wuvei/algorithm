class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int m = grid.size(), n = grid[0].size(), count = 0;
        int dirx[] = {-1, 1, 0, 0}, diry[] = {0, 0, -1, 1}; 
        vector<vector<int> > record(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!record[i][j]) {
                    if (grid[i][j] == '1') {
                        q.push(make_pair(i, j));
                        count++;
                    }
                    record[i][j] = 1;
                    while(!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int x = p.first + dirx[k], y = p.second + diry[k];
                            if (x >= 0 && x < m && y < n && y >= 0 && 
                            !record[x][y] && grid[x][y] == '1') {
                                q.push(make_pair(x, y));
                                record[x][y] = 1;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};