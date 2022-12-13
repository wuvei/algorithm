class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<vector<int>> sort_query(k);
        for (int i = 0; i < k; ++i) {
            sort_query[i] = {queries[i], i};
        }
        sort(sort_query.begin(), sort_query.end());

        int m = grid.size(), n = grid[0].size();
        int dir[5] = {1, 0, -1, 0, 1};
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int>> > pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        vector<int> ans(k);
        int cnt = 0;
        for (auto &q: sort_query) {
            while (!pq.empty() && pq.top()[0] < q[0]) {
                auto &temp = pq.top();
                int x = temp[1], y = temp[2];
                pq.pop();
                ++cnt;
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dir[i], ny = y + dir[i + 1];
                    if (nx < m && nx >= 0 && ny >= 0 && ny < n && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        pq.push({grid[nx][ny], nx, ny});
                    }
                }
            }
            ans[q[1]] = cnt;
        }
        return ans;
    }
};