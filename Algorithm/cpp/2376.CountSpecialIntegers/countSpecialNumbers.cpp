class Solution {
public:
    static constexpr int fac[] = {
        1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800
    };
    inline int A(int x, int y) {
        return fac[x] / fac[x - y];
    }
    int countNumbersWithUniqueDigits(int n) {
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += 9 * A(9, i);
        } 
        return ret;
    }
    int countSpecialNumbers(int n) {
        string n_str = to_string(n);
        int m = n_str.size();
        // 第一部分，m-1位的unique数字计算
        int ret = countNumbersWithUniqueDigits(m - 1); // 不包含0
        vector<bool> used(10, false);
        // 第二部分，m位的整数，从高位开始计算
        bool is_n_valid = true;
        for (int i = 0; i < m; i++) {
            char k = n_str[i] - '0';
            int cnt = 0;
            // 第0位不能为0
            for (int j = (i == 0); j < k; j++) {
                cnt += (!used[j]);
            }
            int A_ = A(10 - (i + 1), m - (i + 1));
            ret += (cnt * A_);
            if (used[k]) {
                is_n_valid = false;
                break;
            }
            used[k] = true;
        }
        ret += is_n_valid;
        return ret;
    }
};

// https://leetcode.cn/problems/count-special-integers/solution/pai-lie-zu-he-ji-suan-by-taiyuzhuo-2i4z/