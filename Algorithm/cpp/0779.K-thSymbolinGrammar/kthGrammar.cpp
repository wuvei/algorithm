class Solution {
public:
    int table[2][2] = {{1, 0}, {0, 1}};
    int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;
        int t = kthGrammar(n - 1, (k + 1) >> 1);
        return table[t][k & 1];
    }
};

class Solution {
public:
    int kthGrammar(int n, int k) {
        return __builtin_popcount(k - 1) & 1;
    }
};

// 作者：lcbin
// 链接：https://leetcode.cn/problems/k-th-symbol-in-grammar/solution/by-lcbin-2eyj/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。