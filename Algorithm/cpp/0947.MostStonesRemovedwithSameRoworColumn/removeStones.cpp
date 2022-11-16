class Solution {
public:
    class UnionFind {
    public:
        UnionFind(int n): size(n), p(n), rank(n, 1) {
            iota(p.begin(), p.end(), 0);
        }
        int find(int e) {
            int t = e;
            while (p[t] != t) {
                t = p[t];
            }
            while (p[e] != t) {
                int temp = p[e];
                p[e] = t;
                e = temp;
            }
            return t;
        }
        bool connect(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return false;
            }
            if (rank[x] < rank[y]) {
                swap(x, y);
            }
            p[y] = x;
            rank[x] += rank[y];
            return true;
        }
        int groups() {
            int ans = 0;
            for (int i = 0; i < size; ++i) {
                if (p[i] == i)
                    ++ans;
            }
            return ans;
        }
    private:
        vector<int> p, rank;
        int size;
    };
    
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> m1, m2;
        int n = stones.size();
        if (n == 1) return 0;
        for (int i = 0; i < n; ++i) {
            auto &v = stones[i];
            m1[v[0]].push_back(i);
            m2[v[1]].push_back(i);
        }
        UnionFind uf(n);
        auto f = [&](unordered_map<int, vector<int>> &m) {
            for (auto &[k, v]: m) {
                for (int i = 0; i < v.size() - 1; ++i) {
                    for (int j = i + 1; j < v.size(); ++j) {
                        uf.connect(v[i], v[j]);
                    }
                }
            }
        };
        f(m1);
        f(m2);
        return n - uf.groups();
    }
};