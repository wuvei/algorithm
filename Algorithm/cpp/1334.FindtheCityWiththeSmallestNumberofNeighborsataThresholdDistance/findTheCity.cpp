class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 0x3f3f3f3f;
        int dist[n][n];
        memset(dist,INF,sizeof(dist));
        for(int i=0;i<n;i++)
        dist[i][i]=0;
        for(int i=0;i<edges.size();i++){
            dist[edges[i][0]][edges[i][1]]=edges[i][2];
            dist[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int id=-1, minCnt=INF;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold)
                    cnt++;
            }
            if(cnt<=minCnt){
                minCnt=cnt;
                id=i;
            }
        }
        return id;
    }
};

// 作者：sui-xin-yuan
// 链接：https://leetcode-cn.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/solution/zui-duan-lu-jing-mo-ban-da-ji-he-cban-fl-gs7u/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。