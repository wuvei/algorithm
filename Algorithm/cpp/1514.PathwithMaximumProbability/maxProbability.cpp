class Solution {
public:
    vector<vector<pair<int, double> > > g;
    vector<double> dist;
    vector<bool> st;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        g.resize(n);
        dist.resize(n, 0.0);
        st.resize(n, false);
        for(int i = 0; i < edges.size(); i++) {
            int x = edges[i][0], y = edges[i][1];
            double z = succProb[i];
            g[x].push_back({y, z});
            g[y].push_back({x, z});
        }
        spfa(start);
        return dist[end];
    }
    
    void spfa(int s){
        dist[s] = 1;
        queue<int> q;
        q.push(s);
        st[s] = true;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            st[t] = false;
            for (const auto &[v, w]: g[t]) {
                if (dist[v] < dist[t] * w) {
                    dist[v] = dist[t] * w;
                    if (!st[v])
                        q.push(v);
                }
            }
        }
    }
};

//作者：acvv_yaojun
//链接：https://leetcode-cn.com/problems/path-with-maximum-probability/solution/1514-gai-lu-zui-da-de-lu-jing-zui-duan-l-1ij9/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。