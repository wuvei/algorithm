class Solution {
private:
    vector<int> fa, mi, rank;
public:
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        int a = find(x), b = find(y);
        if (a == b) {
            return false;
        }
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        fa[b] = a;
        rank[a] += rank[b];
        mi[a] = min(mi[a], mi[b]);
        return true; 
    }
    int minScore(int n, vector<vector<int>>& roads) {
        fa.resize(n + 1);
        mi.resize(n + 1, 1e6);
        rank.resize(n + 1, 1);
        std::iota(fa.begin(), fa.end(), 0);
        for(auto& r : roads) {
            int a = find(r[0]), b = find(r[1]), c = r[2];
            mi[a] = min(mi[a], c);
            mi[b] = min(mi[b], c);
            merge(a, b);
        }
        return mi[find(1)];       
    }
};