class Solution {
public:
    class UnionFind {
    public:
        UnionFind(int n) : fa(n), rank(n, 1) {
            std::iota(fa.begin(), fa.end(), 0);
        }
        int find(int x) {
            return x == fa[x] ? x : fa[x] = find(fa[x]);
        }
        void connect(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return;
            if (rank[x] < rank[y]) std::swap(x, y);
            fa[y] = x;
            rank[x] += rank[y];
        }
        long long getPairNum() {
            long long ans = 0, sum = 0;
            for (int i = 0; i < fa.size(); ++i) {
                if (fa[i] == i) {
                    ans += sum * rank[i];
                    sum += rank[i];
                }
            }
            return ans;
        }
    private:
        vector<int> fa, rank;
    };
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto &v : edges) {
            uf.connect(v[0], v[1]);
        }
        return uf.getPairNum();
    }
};