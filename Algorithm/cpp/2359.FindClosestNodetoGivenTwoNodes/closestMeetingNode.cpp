class Solution {
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2) {
        int n = edges.size(), min_dis = n, ans = -1;
        auto calc_dis = [&](int x) -> vector<int> {
            vector<int> dis(n, -1);
            for (int d = 0; x != -1 && dis[x] == -1; x = edges[x])
                dis[x] = d++;
            return dis;
        };
        auto d1 = calc_dis(node1), d2 = calc_dis(node2);
        for (int i = 0; i < n; ++i) {
            if (d1[i] == -1 || d2[i] == -1) continue;
            int d = max(d1[i], d2[i]);
            if (d < min_dis) {
                min_dis = d;
                ans = i;
            }
        }
        return ans;
    }
};