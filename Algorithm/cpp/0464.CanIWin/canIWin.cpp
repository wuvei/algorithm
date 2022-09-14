auto _{ []() noexcept {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}() };
bitset<1<<21> cache;
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((1 + maxChoosableInteger) * maxChoosableInteger < desiredTotal << 1) {
            return false;
        }
        cache.reset();
        mc = maxChoosableInteger;
        return dfs(desiredTotal, 0);
    }

    int dfs(int tgt, int state){
        if(cache[state | 1]) {
            return cache[state];
        }
        cache[state | 1] = 1;
        int s = ~state ^ 1, p = __builtin_ffs(s) - 1;
        while(p <= mc){
            if(tgt - p <= 0 || !dfs(tgt - p, 1 << p | state)) {
                return cache[state] = 1;
            }
            s ^= 1 << p;
            p = __builtin_ffs(s) - 1;
        }
        return cache[state] = 0;
    }
private:
    int mc;
};    

// 作者：MuriyaTensei
// 链接：https://leetcode.cn/problems/can-i-win/solution/c-shuang-bai-by-muriyatensei-4y1e/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。