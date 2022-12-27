class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        cnt = vector<int>(N, 1);
        dist = vector<int>(N, 0);
        g = vector<vector<int> >(N);
        num = N;

        for(auto &i : edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        dfs(0, -1);

        fun(0, -1);
        return dist;
    }

    void fun(int root, const int fa){
        if(fa != -1)
            dist[root] = dist[fa] + num - cnt[root] - cnt[root];
        
        for(int i : g[root]){
            if(i == fa)
                continue;
            fun(i, root);
        }
    }

    void dfs(int root, const int fa){
        for(int i: g[root]){
            if(i == fa)
                continue;
            dfs(i, root);
            cnt[root] += cnt[i];
            dist[root] += dist[i];
        } 
        dist[root] += cnt[root]  - 1;
    }

private:
    vector<int> cnt, dist;
    vector<vector<int> > g;
    int num;
};

// 作者：Computer Science Global Optim
// 链接：https://leetcode.cn/problems/sum-of-distances-in-tree/solutions/659887/c-dfsling-lei-jie-fa-by-raymond_yp-ijw9/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。