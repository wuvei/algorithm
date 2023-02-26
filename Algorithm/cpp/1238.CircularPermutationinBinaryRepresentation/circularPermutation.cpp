class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int tot = 1 << n;
        vector<int> ans(tot);
        ans[0] = start;
        vector<bool> vis(tot, false);
        vis[start] = true;
        auto check = [&]() {
            int t = ans[0] ^ ans[tot - 1];
            if ((t & (t - 1)) == 0) return true;
            return false;
        };
        function<bool(int)> f = [&](int idx) {
            if (idx == tot - 1) {
                if (check()) return true;
                return false;
            }
            for (int i = 0, mask = 1; i < n; ++i, mask <<= 1) {
                int next = mask ^ ans[idx];
                if (vis[next]) continue;
                ans[idx + 1] = next;
                vis[next] = true;
                if (f(idx + 1)) return true;
                vis[next] = false;
            }
            return false;
        };
        f(0);
        return ans;
    }
};

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans(1 << n);
        for (int i = 0; i < 1 << n; ++i) {
            ans[i] = i ^ (i >> 1) ^ start;
        }
        return ans;
    }
};

// 作者：ylb
// 链接：https://leetcode.cn/problems/circular-permutation-in-binary-representation/solutions/2128016/python3javacgotypescript-yi-ti-shuang-ji-zhm7/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。