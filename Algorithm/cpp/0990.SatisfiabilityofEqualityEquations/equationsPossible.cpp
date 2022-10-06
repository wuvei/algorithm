class Solution {
public:
    class UnionFind {
    public:
        UnionFind(int n): size(n), parents(n), rank(n, 1) {
            std::iota(parents.begin(), parents.end(), 0);
        }

        int find(int x) {
            return parents[x] == x ? x : parents[x] = find(parents[x]);
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
            parents[y] = x;
            rank[x] += rank[y];
            return true;    
        }
    private:
        int size = 0;
        vector<int> parents, rank;
    };
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        unordered_set<string> neq;
        string t1(2, ' ');
        for (string &s: equations) {
            if (s[1] == '=') {
                uf.connect(s[0] - 'a', s[3] - 'a');
            }
            else {
                t1[0] = s[0];
                t1[1] = s[3];
                neq.insert(t1);
            }
        }
        for (auto &t: neq) {
            if (uf.find(t[0] - 'a') == uf.find(t[1] - 'a')) {
                return false;
            }
        }
        return true;
    }
};