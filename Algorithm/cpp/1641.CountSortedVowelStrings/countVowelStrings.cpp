class Solution {
public:
    int C(int n, int m) {
        if (n == m || m == 0) return 1;
        int ans = 1;
        m = min(m, n-m);
        for (int i = 1; i <= m; i++) ans = ans * (n-i+1) / i;
        return ans;
    }

    int countVowelStrings(int n) {
        return C(n + 4, 4);
    }
};


class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};

// 作者：zerotrac2
// 链接：https://leetcode.cn/problems/count-sorted-vowel-strings/solution/tong-ji-zi-dian-xu-yuan-yin-zi-fu-chuan-de-shu-mu-/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。