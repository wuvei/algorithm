class Solution {
public:
    const int INF = 0x3f3f3f3f;  //INF + INF 不会爆int
    int f[105][25][105];
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                f[i][j][0] = INF;
            }
        }

        for (int i = 1; i <= m; i++){
            int color = houses[i - 1];
            for (int j = 1; j <= n; j++){
                for (int k = 1; k <= target; k++){
                    if (k > i) {
                        f[i][j][k] = INF;
                        continue;
                    }
                    if (color != 0) {
                        if (j == color) {
                            int cur = INF;
                            for (int p = 1; p <= n; p++){
                                if (p != j) 
                                    cur = min(cur, f[i - 1][p][k - 1]);
                            }
                            f[i][j][k] = min(cur,f[i - 1][j][k]);
                        }
                        else f[i][j][k] = INF;
                    }
                    else {
                        int u = cost[i - 1][j - 1];
                        int cur = INF;
                        for(int p = 1; p <= n; p++)
                            if(p != j) cur = min(cur,f[i - 1][p][k - 1] + u);
                        f[i][j][k] = min(cur,f[i - 1][j][k] + u);
                    }
                }
            }
        }
        int ans = INF;
        for(int i = 1; i <= n; i++){
            ans = min(ans,f[m][i][target]);
        }
        return ans == INF ? -1 : ans;
    }
};

// https://leetcode.cn/problems/paint-house-iii/solution/gong-shui-san-xie-san-wei-dong-tai-gui-h-ud7m/