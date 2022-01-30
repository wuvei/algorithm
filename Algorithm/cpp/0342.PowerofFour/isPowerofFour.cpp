class Solution {
public:
    bool isPowerOfFour(int n) {
        bitset<32> b(n);
        if (b.count() != 1) return false;
        for (int i = 0; i < 32; i += 2) {
            if (b[i]) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        bitset<32> b(n);
        if (b.count() != 1) return false;
        int i = 0;
        for (; i < 32 && !b[i]; i++);
        if ((i & 1) == 0) return true;
        return false;
    }
};


// 首先我们考虑一个数字是不是 2 的（整数）次方：如果一个数字 n 是 2 的整数次方，那么它 的二进制一定是 0...010...0 这样的形式；考虑到 n − 1 的二进制是 0...001...1，这两个数求按位与 的结果一定是 0。因此如果 n & (n - 1) 为 0，那么这个数是 2 的次方。

// 如果这个数也是 4 的次方，那二进制表示中 1 的位置必须为奇数位。我们可以把 n 和二进制 的 10101...101（即十进制下的 1431655765）做按位与，如果结果不为 0，那么说明这个数是 4 的次方。
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && !(n & (n - 1)) && (n & 1431655765);
    }
};
