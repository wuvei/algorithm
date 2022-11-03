class Solution {
public:
    enum Dir {
        DOWN, LEFT, RIGHT
    };
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            int x = 0, y = i;
            Dir d = DOWN;
            while (x < m && y >= 0 && y < n) {
                switch (d) {
                    case DOWN:
                        if (grid[x][y] == 1) {
                            ++y;
                            d = RIGHT;
                        }
                        else {
                            --y;
                            d = LEFT;
                        }
                        break;
                    case LEFT:
                        if (grid[x][y] == -1) {
                            ++x;
                            d = DOWN;
                        }
                        else y = -1;
                        break;
                    case RIGHT:
                        if (grid[x][y] == 1) {
                            ++x;
                            d = DOWN; 
                        }
                        else y = -1;
                        break;
                    default:
                        break;
                }
            }
            if (x == m) ans[i] = y;
        }
        return ans;
    }
};