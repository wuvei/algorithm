class Solution {
public:
    class UF {
    private:
        vector<int> parent, rank;
    public:
        UF (int n) {
            parent = vector<int>(n);
            rank = vector<int>(n, 1);
            for (int i = 0; i < n; ++i)
                parent[i] = i;
        }
        void connect(int a, int b) {
            a = get_parent(a);
            b = get_parent(b);
            if (rank[a] < rank[b]) {
                swap(a, b);
            }
            rank[a] += rank[b];
            parent[b] = a;
        }
        int get_parent(int a) {
            if (parent[a] != a)
                parent[a] = get_parent(parent[a]);
            return parent[a];
        }
        bool is_connected(int a, int b) {
            return get_parent(a) == get_parent(b);
        }
    };
    int minCostConnectPoints(vector<vector<int> >& points) {
        int n = points.size();
        vector<vector<int> > edges;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                edges.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j});
            }
        }
        UF uf(n);
        sort(edges.begin(), edges.end());
        int count = 0, ans = 0;
        for (int i = 0; i < edges.size() && count < n - 1; i++) {
            if (!uf.is_connected(edges[i][1], edges[i][2])) {
                ans += edges[i][0];
                ++count;
                uf.connect(edges[i][1], edges[i][2]);
            }
        }
        return ans;
    }
};

// From Leetcode
class UnionFindLC1584 {
private:
    vector<int>parent;
    vector<int>size;
    vector<int>rank;
    int count;
public:
    UnionFindLC1584(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n,1);
        rank.resize(n);
        count = n;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        } else {
            if (rank[rootX] < rank[rootY]) {
                swap(rootX, rootY);
            }
            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            --count;
            return true;
        }
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    int getCount() const {
        return count;
    }
};
class BIT {
public:
    vector<int>tree, ids;
    int n;
    BIT(int n) {
        this->n = n;
        tree.resize(n,INT_MAX);
        ids.resize(n,-1);
    }
    int lowbit(int x) {
        return x&(-x);
    }
    void update(int pos, int val, int id) {
        while (pos>0) {
            if (tree[pos] > val) {
                tree[pos] = val;
                ids[pos] = id;
            }
            pos -= lowbit(pos);
        }
    }
    int query(int pos) {
        int minVal = INT_MAX;
        int id = -1;
        while (pos < n) {
            if (minVal > tree[pos]) {
                minVal = tree[pos];
                id = ids[pos];
            }
            pos += lowbit(pos);
        }
        return id;
    }
};

class Solution {
private:
    struct Edge {
        int len, x, y;
        Edge(int l, int i, int j): len(l), x(i), y(j) {
        };
        bool operator<(const Edge& a) const {
            return len < a.len;
        }
    };
    struct Postion {
        int id, x, y;
        bool operator<(const Postion& a) const {
            return x == a.x ? y < a.y : x < a.x;
        }
    };
public:
    vector<Edge>edges;
    vector<Postion>positions;
    void build(int n) {
        sort(positions.begin(), positions.end());
        vector<int>a(n), b(n);
        for (int i=0; i<n; ++i) {
            a[i] = b[i] = positions[i].y - positions[i].x;
        }
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        int size = (int)b.size();
        BIT bit(size+1);
        for (int i=n-1; i>=0; --i) {
            int pos = lower_bound(b.begin(), b.end(), a[i])-b.begin()+1;
            int j = bit.query(pos);
            if (j != -1) {
                int dist = abs(positions[i].x - positions[j].x) + abs(positions[i].y - positions[j].y);
                edges.emplace_back(dist, positions[i].id, positions[j].id);
            }
            bit.update(pos, positions[i].x + positions[i].y, i);
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = (int)points.size();
        positions.resize(n);
        for (int i=0; i<n; ++i) {
            positions[i].x = points[i][0];
            positions[i].y = points[i][1];
            positions[i].id = i;
        }
        build(n);
        for (int i=0; i<n; ++i) {
            swap(positions[i].x, positions[i].y);
        }
        build(n);
        for (int i=0; i<n; ++i) {
            positions[i].x = -positions[i].x;
        }
        build(n);
        for (int i=0; i<n; ++i) {
            swap(positions[i].x, positions[i].y);
        }
        build(n);
        UnionFindLC1584 uf(n);
        sort(edges.begin(), edges.end());
        int ans = 0;
        for (auto& [len, x, y] : edges) {
            if (uf.isConnected(x, y)) {
                continue;
            }
            uf.unite(x, y);
            ans += len;
        }
        return ans;
    }
};

// https://leetcode-cn.com/problems/min-cost-to-connect-all-points/solution/lian-jie-suo-you-dian-de-zui-xiao-fei-yo-kcx7/
// https://leetcode-cn.com/problems/min-cost-to-connect-all-points/solution/leetcodeguan-fang-ti-jie-onlognzhu-shi-b-p9kq/