class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        //---------------------最小堆+dijkstra算法 -----------------------//
        int INF = 1e9;
        unordered_map<int, vector<pair<int, int>>> adjvex;
        for (auto v : times) {
            adjvex[v[0]].push_back({v[1], v[2]});
        }

        vector<int> dist(n + 1, INF);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minHeap;
        minHeap.push({0, k});
        while (!minHeap.empty()) {
            auto [d, x] = minHeap.top();
            minHeap.pop();
            if (d > dist[x] || dist[x] == INF)
                continue;
            for (auto [y, cost] : adjvex[x]) {
                if (dist[x] + cost < dist[y]) {
                    dist[y] = dist[x] + cost;
                    minHeap.push({dist[y], y});
                }
            }
        }
        int res = *max_element(dist.begin() + 1, dist.end());  
        return (res != INF ? res : -1);
    }   
};

// 作者：QRhqcDD90G
// 链接：https://leetcode-cn.com/problems/network-delay-time/solution/cpython3java-1po-su-dijkstrasuan-fa-2zui-ks36/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。