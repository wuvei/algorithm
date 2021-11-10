class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> a(3);
        for (int x : stones)
            a[x % 3] ++ ;
        int small = min(a[1], a[2]), large = max(a[1], a[2]);
        if (a[0] % 2 == 0) {
            if (small > 0)
                return true;
            return false;
        }
        else {
            if (large - small > 2)
                return true;
            return false;
        }
    }
};

// https://python.iitter.com/other/122261.html
// 由于题目只需判断是和是否为3的倍数，故可将所有数模3后记录数量
// 主要思想：让对手凑成3
// 先手不能选0，只能选1或2
// 选1时，序列为1121212…
// 选2时，序列为22121212…
// 期间选0不影响顺序
// 记1和2数量大的数为large，小的为small
// 此序列必定导致1或2数量不足，此时考虑0的个数的奇偶性，若为偶，先手必胜，条件为small>0
// small等于0时可能存在
//     1或2数量为0，对手无法通过1+2凑成3，由于先手必选1或2，对手选0即可，0数量为偶数，交替选完后，石子被选完或者我方选到3个相同，故必败
//     1和2全为0，只能选0，必败
// 当0的数量时奇数时，先手不一定必败，由于是奇数选完0后双方状态交换，1和2相互抵消后，若剩余的相同数字大于2个，则先手必胜，否则提前选完所有数，先手必败

// https://leetcode-cn.com/problems/stone-game-ix/solution/xiang-xi-tui-dao-yi-xia-ge-chong-qing-ku-g0aq/