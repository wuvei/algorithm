class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k) {
        int ans = INT_MAX;
        deque<pair<long, int>> q;
        q.emplace_back(0, -1);
        long cur_s = 0L;
        for (int i = 0; i < nums.size(); ++i) {
            cur_s += nums[i]; // 计算前缀和
            while (!q.empty() && cur_s - q.front().first >= k) {
                ans = min(ans, i - q.front().second);
                q.pop_front(); // 优化一
            }
            while (!q.empty() && q.back().first >= cur_s)
                q.pop_back(); // 优化二
            q.emplace_back(cur_s, i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// 作者：endlesscheng
// 链接：https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/solution/liang-zhang-tu-miao-dong-dan-diao-dui-li-9fvh/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。