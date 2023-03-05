class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        int n = grid.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j)
                for (int k = i; k < i + 3; ++k)
                    grid[i][j] = max(grid[i][j], *max_element(grid[k].begin() + j, grid[k].begin() + j + 3));
            grid[i].resize(n - 2);
        }
        grid.resize(n - 2);
        return grid;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/largest-local-values-in-a-matrix/solutions/1746845/yuan-di-xiu-gai-by-endlesscheng-m1k3/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。