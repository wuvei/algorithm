// Kruscal
#include <algorithm>
using namespace std;
class UF {
public:
    UF(int num): n(num), root(vector<int>(n + 1, -1)), size(vector<int>(n + 1, 1)) {}
    int find (int v) {
        if (root[v] == -1)
            return v;
        else root[v] = find(root[v]);
        return root[v];
    }
    void unionSet(int x, int y) {
      int xx = find(x), yy = find(y);
      if (xx == yy) return;
      if (size[xx] > size[yy])
        swap(xx, yy);
      root[xx] = yy;
      size[yy] += size[xx];
    }
    bool is1Tree() {
        for (int e: size)
            if (e == n) return true;
        return false;
    }
private:
    int n;
    vector<int> root, size;
};

int getMinimumCost(int n, int m, vector<vector<int>> &connections) {
	sort(connections.begin(), connections.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a[2] == b[2]) return a[0] < b[0];
        return a[2] < b[2];
    });
    UF uf(n);
    int cost = 0;
    for (auto &v: connections) {
        if (uf.find(v[0]) == uf.find(v[1])) continue;
        cost += v[2];
        uf.unionSet(v[0], v[1]);
    }
    return uf.is1Tree()? cost: -1;
}