// Bit
class Solution {
public:
    int mirrorReflection(int p, int q){
        int pqOr = p | q;
        int lowestBit = pqOr & (-pqOr);
        if (!(p & lowestBit)) return 2;
        if (!(q & lowestBit)) return 0;
        return 1;
    }
// 作者：rand1925
// 链接：https://leetcode.cn/problems/mirror-reflection/solution/chun-wei-yun-suan-bu-yong-gcdbu-yong-xun-huan-chan/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
};

// GCD
class Solution {
public:
    int gcd(int a, int b) {
        if (a == b) return a;
        if (a & 1) {
            if (b & 1) return gcd(std::abs(a - b), std::min(a, b));
            else return gcd(a, b >> 1);
        }
        else {
            if (b & 1) return gcd(a >> 1, b);
            else return 2 * gcd(a >> 1, b >> 1);
        }
    }
    int mirrorReflection(int p, int q){
        int m = gcd(p, q);
        if (((p / m) & 1) == 0) return 2;
        else if (((q / m) & 1) == 0) return 0;
        else return 1;
    }
    
};