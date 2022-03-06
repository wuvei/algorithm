class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (color[i] != -1) continue;
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int e: graph[node]) {
                    if (color[e] == -1) {
                        q.push(e);
                        color[e] = 1 - color[node];
                    }
                    else if (color[e] == color[node])
                        return false;
                }
            }
        }
        return true;
    }
};

// Union-Find
class Solution {
public:
    int find(vector<pair<int,int>> &parent, int k){
        if(parent[k].first == -1 || parent[k].first==k){
            parent[k].first = k;
            return k;
        }
        parent[k].first=find(parent,parent[k].first);
        return parent[k].first;
    }
    
    void unionFind(vector<pair<int,int>> &parent, int x, int y){
       int a = find(parent,x);
        int b = find(parent,y);
        if(a != b){
           if(parent[a].second < parent[b].second){
               parent[a].first=b;
           }else if(parent[a].second > parent[b].second){
                parent[b].first=a;
            }else{
                parent[b].first=a;
                parent[a].second += 1;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n =graph.size();
        vector<pair<int,int>> parent(n,{-1,0});
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
             // node and neighbour shouldn't belong to same set in bipartite
                if(find(parent,i) == find(parent,graph[i][j])){
                    return false;
                }
                // all node neighbours should belong to one set
                unionFind(parent,graph[i][j],graph[i][0]);
            }
        }
        return true;
    }
};
// https://leetcode.com/problems/is-graph-bipartite/discuss/1431464/C%2B%2B-Union-find-solution-optimized-with-union-by-rank