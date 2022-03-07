class Solution {
public:
    struct UF{
        vector<int> id, size;
        UF(int n): id(vector<int>(n, 0)), size(vector<int>(n, 1)) {
            iota(id.begin(), id.end(), 0);
        }
        int find(int p) {
            int cur = p;
            while (cur != id[cur])
                cur = id[cur];
            while (p != id[p]) {
                int temp = id[p];
                id[p] = cur;
                p = temp;
            }
            return cur;
        }

        void connect(int p, int q) {
            int x = find(p), y = find(q);
            if (x == y) return;
            if (size[x] > size[y]) swap(x, y);
            id[x] = y;
            size[y] += size[x];
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF uf(n + 1);
        for (auto e: edges) {
            int u = e[0], v = e[1];
            if (uf.isConnected(u, v)) return e;
            uf.connect(u, v)
        }
        return {-1, -1};
    }
};