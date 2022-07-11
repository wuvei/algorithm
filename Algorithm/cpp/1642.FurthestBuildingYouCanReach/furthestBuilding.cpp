class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int> > pq;
        int brick_needed = 0;
        for (int i = 0; i < heights.size() - 1; ++i) {
            int diff = heights[i + 1]  - heights[i];
            if (diff <= 0) continue;
            if (pq.size() < ladders)
                pq.push(diff);
            else if (!pq.empty() && pq.top() < diff) {
                brick_needed += pq.top();
                pq.pop();
                pq.push(diff);
            }
            else brick_needed += diff;
            if (brick_needed > bricks)
                return i;
        }
        return heights.size() - 1;
    }
};