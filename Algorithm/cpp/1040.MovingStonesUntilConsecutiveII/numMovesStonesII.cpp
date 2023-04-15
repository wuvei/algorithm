class Solution {
public:
    vector<int> numMovesStonesII(vector<int> &s) {
        sort(s.begin(), s.end());
        int n = s.size();
        int e1 = s[n - 2] - s[0] - n + 2;
        int e2 = s[n - 1] - s[1] - n + 2; // 计算空位
        int max_move = std::max(e1, e2);
        if (e1 == 0 || e2 == 0) // 特殊情况：没有空位
            return {std::min(2, max_move), max_move};
        int max_cnt = 0, left = 0;
        for (int right = 0; right < n; ++right) { // 滑动窗口：枚举右端点
            while (s[right] - s[left] + 1 > n) // 窗口大小大于 n
                ++left;
            max_cnt = max(max_cnt, right - left + 1); // 维护窗口内的最大石子数
        }
        return {n - max_cnt, max_move};
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/moving-stones-until-consecutive-ii/solutions/2212638/tu-jie-xia-tiao-qi-pythonjavacgo-by-endl-r1eb/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。