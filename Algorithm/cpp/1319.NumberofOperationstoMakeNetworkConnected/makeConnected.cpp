class Solution {
public:
    class UnionFind {
    public:
        UnionFind(int n) : fa(n), rank(n, 1) {
            std::iota(fa.begin(), fa.end(), 0);
        }
        int find(int x) {
            return fa[x] == x ? x : fa[x] = find(fa[x]);
        }
        void merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return;
            if (rank[x] < rank[y]) swap(x, y);
            fa[y] = x;
            rank[x] += rank[y];
        }
        int countConnects() {
            int cnt = 0;
            for (int i = 0; i < fa.size(); ++i)
                cnt += i == fa[i];
            return cnt;
        }
    private:
        vector<int> fa, rank;
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < n - 1) return -1;
        UnionFind uf(n);
        for (auto &v : connections) {
            uf.merge(v[0], v[1]);
        }
        return uf.countConnects() - 1;
    }
};