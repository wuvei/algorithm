class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        dominoes.reserve(n + 2);
        dominoes.insert(0, 1, 'L');
        dominoes.push_back('R');
        int l = 0;
        string res = "";
        res.reserve(n);
        for (int r = 1; r <= n + 1; ++r) {
            if (dominoes[r] == '.') {
                continue;
            }
            if (l != 0) {
                res += dominoes[l];
            }
            int mid = r - l - 1;
            if (dominoes[l] == dominoes[r]) {
                res += string(mid, dominoes[l]);
            } else if (dominoes[l] == 'L' && dominoes[r] == 'R') {
                res += string(mid, '.');
            } else {
                res += string(mid >> 1, 'R') + ((mid & 1) ? "." : "") + string(mid >> 1, 'L');
            }
            l = r;
        }
        return res;
    }
};

// 作者：fuxuemingzhu
// 链接：https://leetcode.cn/problems/push-dominoes/solution/fu-xue-ming-zhu-miao-dong-xi-lie-xiang-x-xkts/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。