class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };
        int m = queries.size();
        vector<bool> ans(m);
        vector<int> qid(m);
        iota(qid.begin(), qid.end(), 0);
        sort(qid.begin(), qid.end(), [&](int i, int j) { return queries[i][2] < queries[j][2]; });
        int j = 0;
        for (int i : qid) {
            int a = queries[i][0], b = queries[i][1], limit = queries[i][2];
            while (j < edgeList.size() && edgeList[j][2] < limit) {
                int u = edgeList[j][0], v = edgeList[j][1];
                p[find(u)] = find(v);
                ++j;
            }
            ans[i] = find(a) == find(b);
        }
        return ans;
    }
};

// 作者：ylb
// 链接：https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/solutions/2019596/by-lcbin-uwd2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。