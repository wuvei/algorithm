class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        deque<int> q;
        int n = boxes.size();
        vector<int> dp(n + 1);
        dp[n] = 0;
        int cur_box_count = 0, sum_w = 0, r = n - 1;
        cur_box_count += 1;
        sum_w += boxes[n - 1][1];
        dp[n - 1] = 2;
        for (int i = n - 2; i >= 0; --i) {
            auto& box = boxes[i];
            cur_box_count += 1;
            sum_w += box[1];
            if (i + 1 <= r && boxes[i][0] != boxes[i + 1][0]) {
                q.push_front(i);
            }
            while (cur_box_count > maxBoxes || sum_w > maxWeight) {
                cur_box_count -= 1;
                sum_w -= boxes[r][1];
                --r;
                if (!q.empty() && (q.back() + 1) > r) {
                    q.pop_back();
                }
                
            }
            if (q.size() >= 1) {
                dp[i] = q.size() + 1 + dp[q.back() + 1];
            } else {
                dp[i] = 0x7fffffff;
            }
            dp[i] = min(dp[i], (int)q.size() + 2 + dp[r + 1]);
        }
        return dp[0];
    }
};