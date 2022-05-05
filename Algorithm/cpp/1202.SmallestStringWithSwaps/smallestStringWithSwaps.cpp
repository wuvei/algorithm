class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int find(int a) {
        if (a != parent[a])
            parent[a] = find(parent[a]);
        return parent[a];
    }
    void connect(int a, int b) {
        parent[find(b)] = find(a);
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.size());
        for (auto &v: pairs) {
            uf.connect(v[0], v[1]);
        }
        unordered_map<int, priority_queue<char, vector<char>, greater<char> > > data;
        for (int i = 0; i < s.size(); ++i)
            data[uf.find(i)].push(s[i]);

        for (int i = 0; i < s.size(); ++i) {
            int temp = uf.find(i);
            s[i] = data[temp].top();
            data[temp].pop();
        }
        return s;
    }
};