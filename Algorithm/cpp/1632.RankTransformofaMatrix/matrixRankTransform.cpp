class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        map<int, vector<pair<int, int>>> d;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d[matrix[i][j]].push_back({i, j});
            }
        }
        vector<int> rowMax(m), colMax(n);
        vector<vector<int>> ans(m, vector<int>(n));
        for (auto& [_, ps] : d) {
            UnionFind uf(m + n);
            vector<int> rank(m + n);
            for (auto& [i, j] : ps) {
                uf.unite(i, j + m);
            }
            for (auto& [i, j] : ps) {
                rank[uf.find(i)] = max({rank[uf.find(i)], rowMax[i], colMax[j]});
            }
            for (auto& [i, j] : ps) {
                ans[i][j] = rowMax[i] = colMax[j] = 1 + rank[uf.find(i)];
            }
        }
        return ans;
    }
};

// 作者：ylb
// 链接：https://leetcode.cn/problems/rank-transform-of-a-matrix/solutions/2075493/by-lcbin-ll29/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。