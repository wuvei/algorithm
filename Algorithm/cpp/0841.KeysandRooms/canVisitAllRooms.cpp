class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visit(n, false);
        visit[0] = true;
        --n;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int e = q.front();
            q.pop();
            for (int next: rooms[e]) {
                if (!visit[next]) {
                    q.push(next);
                    visit[next] = true;
                    --n;
                }
            }
        }
        return n == 0;
    }
};