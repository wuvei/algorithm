class Solution {
public:
    using LL=long long;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int> > free_rooms;
        priority_queue<pair<LL, int>, vector<pair<LL, int> >, greater<pair<LL, int> > > ends;
        for (int i = 0; i < n; ++i) {
            free_rooms.push(i);
        }
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        for (auto &m: meetings) {
            while (!ends.empty() && ends.top().first <= m[0]) {
                auto &temp = ends.top();
                free_rooms.push(temp.second);
                ends.pop();
            }
            if (free_rooms.empty()) {
                auto [end_time, room] = ends.top();
                ends.pop();
                ends.push({end_time + m[1] - m[0], room});
                ++count[room];
            }
            else {
                int room = free_rooms.top();
                free_rooms.pop();
                ends.push({m[1], room});
                ++count[room];
            }
        }
        auto result = std::max_element(count.begin(), count.end());
        return std::distance(count.begin(), result);
    }
};