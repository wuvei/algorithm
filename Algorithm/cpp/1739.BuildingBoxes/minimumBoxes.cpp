class Solution {
public:
    int minimumBoxes(int n) {
        int cur = 0, i = 0, j = 0;
        while(cur < n) {
            ++j;
            i += j;
            cur += i;
        }
        if(cur == n) return i;
        cur -= i;
        i -= j;
        j = 0;
        while(cur < n) {
            ++j;
            cur += j;
        }
        return i + j;
    }
};
// https://leetcode.cn/problems/building-boxes/solutions/1129209/zui-qing-xi-de-ti-jie-copywai-guo-you-re-pnlv/