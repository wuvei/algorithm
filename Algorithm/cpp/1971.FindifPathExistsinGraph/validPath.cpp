class Solution {
public:
    class UnionFind {
    private:
        vector<int> p, rank;
    public:
        UnionFind(int n): p(n), rank(n, 1) {
            std::iota(p.begin(), p.end(), 0);
        }
        int find(int a) {
            int t = a;
            while (p[t] != t) {
                t = p[t];
            }
            while (p[a] != a) {
                int next = p[a];
                p[a] = t;
                a = next;
            }
            return t;
        }
        void connect(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (rank[a] < rank[b])
                std::swap(a, b);
            p[b] = a;
            rank[a] += rank[b];
        }
    };
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        for (auto &v: edges) {
            uf.connect(v[0], v[1]);
        }
        return uf.find(source) == uf.find(destination);
    }
};