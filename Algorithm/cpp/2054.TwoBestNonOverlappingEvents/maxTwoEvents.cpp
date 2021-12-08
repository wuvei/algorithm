class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        ios::sync_with_stdio(false);cin.tie(NULL);
        sort(events.begin(), events.end());
        int n = events.size(), ans = 0;
        vector<int> max_after(n, events[n - 1][2]);
        for (int i = n - 2; i >= 0; i--)
            max_after[i] = std::max(events[i][2], max_after[i + 1]);
        
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            int idx = -1;
            //find first index whose start-time is greater than current event's end-time
            while(l <= r){
                int m = r - (r - l) / 2;
                if(events[m][0] > events[i][1]){
                    idx = m;
                    r=m-1;
                }
                else l=m+1;
            }
            if (idx != -1) ans = std::max(ans, events[i][2] + max_after[idx]);
            
        }
        return std::max(ans, max_after[0]);
    }
};

