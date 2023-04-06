class Solution {
public:
    int mergeStones(vector<int> &stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1))
            return -1;

        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; i++)
            s[i + 1] = s[i] + stones[i]; // prefix sum

        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i == j) return 0; // 1 pile
            int &res = memo[i][j]; // reference
            if (res != -1) return res;
            res = INT_MAX;
            for (int m = i; m < j; m += k - 1)
                res = min(res, dfs(i, m) + dfs(m + 1, j));
            if ((j - i) % (k - 1) == 0) // merge into 1
                res += s[j + 1] - s[i];
            return res;
        };
        return dfs(0, n - 1);
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/minimum-cost-to-merge-stones/solutions/2207235/tu-jie-qu-jian-dpzhuang-tai-she-ji-yu-yo-ppv0/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。