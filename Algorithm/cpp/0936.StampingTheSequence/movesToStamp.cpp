class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        size_t m = stamp.size(), n = target.size();
        vector<int> inDegree(n - m + 1, m), q;
        vector<vector<int>> edges(n);
        vector<bool> seen(n, false);
        for (size_t i = 0; i < n - m + 1; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (target[i + j] == stamp[j]) {
                    --inDegree[i];  
                } else {
                    edges[i + j].emplace_back(i);
                }
            }
            if (!inDegree[i]) q.emplace_back(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int cur = q.back();
            q.pop_back();
            ans.emplace_back(cur);
            for (size_t i = 0; i < m; i++) {
                if (!seen[cur + i]) {
                    seen[cur + i] = true;
                    for (auto &&edge : edges[cur + i]) {
                        inDegree[edge] -= 1;
                        if (!inDegree[edge]) q.emplace_back(edge);
                    }
                }
            }
        }
        if (ans.size() < n - m + 1) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 作者：xhctx
// 链接：https://leetcode.cn/problems/stamping-the-sequence/solution/tuo-bu-pai-xu-by-kevinchen147-09ad/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。