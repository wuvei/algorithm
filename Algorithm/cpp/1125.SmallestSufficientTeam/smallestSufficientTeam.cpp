class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people) {
        unordered_map<string, int> sid;
        int m = req_skills.size();
        for (int i = 0; i < m; ++i)
            sid[req_skills[i]] = i; // 字符串映射到下标

        int n = people.size();
        vector<int> mask(n, 0);
        for (int i = 0; i < n; ++i)
            for (auto &s: people[i])
                mask[i] |= 1 << sid[s];

        int u = 1 << m;
        long long all = (1LL << n) - 1;
        vector<vector<long long>> memo(n, vector<long long>(u, -1));
        std::function<long long(int, int)> dfs = [&](int i, int j) -> long long {
            if (j == 0) return 0; // 背包已装满
            if (i < 0) return all; // 没法装满背包，返回全集，这样下面比较集合大小会取更小的
            auto &res = memo[i][j]; // 注意这里是引用，下面会直接修改 memo[i][j]
            if (res != -1) return res;
            auto r1 = dfs(i - 1, j); // 不选 mask[i]
            auto r2 = dfs(i - 1, j & ~mask[i]) | (1LL << i); // 选 mask[i]
            return res = __builtin_popcountll(r1) < __builtin_popcountll(r2) ? r1 : r2;
        };
        auto res = dfs(n - 1, u - 1);

        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if ((res >> i) & 1)
                ans.push_back(i);
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/smallest-sufficient-team/solutions/2214387/zhuang-ya-0-1-bei-bao-cha-biao-fa-vs-shu-qode/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。