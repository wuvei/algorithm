class Solution {
public:
    int numberOfSteps(int num) {
        return num ? 31 - __builtin_clz(num) + __builtin_popcount(num) : 0;
    }
};

// binary search & divide and conquer
class Solution {
public:
    int length(uint num) {
        uint clz = 0;
        if ((num >> 16) == 0) {
            clz += 16;
            num <<= 16;
        }
        if ((num >> 24) == 0) {
            clz += 8;
            num <<= 8;
        }
        if ((num >> 28) == 0) {
            clz += 4;
            num <<= 4;
        }
        if ((num >> 30) == 0) {
            clz += 2;
            num <<= 2;
        }
        if ((num >> 31) == 0) {
            clz += 1;
        }
        return 32 - clz;
    }

    int count(int num) {
        num = (num & 0x55555555) + ((num >> 1) & 0x55555555);
        num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
        num = (num & 0x0F0F0F0F) + ((num >> 4) & 0x0F0F0F0F);
        num = (num & 0x00FF00FF) + ((num >> 8) & 0x00FF00FF);
        num = (num & 0x0000FFFF) + ((num >> 16) & 0x0000FFFF);
        return num;
    }

    int numberOfSteps(int num) {
        return num == 0 ? 0 : length(num) - 1 + count(num);
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-to-zero/solution/jiang-shu-zi-bian-cheng-0-de-cao-zuo-ci-ucaa4/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。