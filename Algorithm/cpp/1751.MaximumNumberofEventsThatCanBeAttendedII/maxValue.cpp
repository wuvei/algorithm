#define ll int
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define vc vector
#define pb push_back
#define pii pair<ll,ll>
#define fr first
#define sc second
#define M 1000000007
class Solution {
public:
    vc<pair<ll,pii>> v;
    vc<ll> v1;
    vc<vc<ll>> dp;
    ll n;
    ll calc(ll i,ll k)
    {
        if(k==0||i==n) return 0;
        ll& ans=dp[i][k];
        if(ans!=-1) return ans;
        ll ind=upper_bound(v1.begin()+i+1,v1.end(),v[i].sc.fr)-v1.begin();
        ans=max(calc(ind,k-1)+v[i].sc.sc,calc(i+1,k));
        return ans;
    }
    int maxValue(vector<vector<int>>& e, int k) 
    {
        n=e.size();
        dp.resize(n+5,vc<ll>(k+5,-1));
        rep(i,0,n) v.pb( {e[i][0], {e[i][1],e[i][2]} } );
        sort(v.begin(),v.end());
        rep(i,0,n) v1.pb(v[i].fr);
        return calc(0,k);
    }
};


class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size(), ans = 0;
        vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
        vector<int> end_time {0};
        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b) -> bool {
            return a[1] < b[1]; 
        });
        
        for (int i = 1; i<= n; i++) {
            auto it = std::lower_bound(end_time.begin(),end_time.end(), events[i-1][0]);
            int t = it - end_time.begin() - 1;
            for (int j = 1; j <= k; j++) {
                dp[i][j] = std::max(dp[i-1][j], events[i-1][2] + dp[t][j-1]);
                ans = std::max(ans, dp[i][j]);
            }
            end_time.push_back(events[i - 1][1]);
        }
        return ans;
    }
};