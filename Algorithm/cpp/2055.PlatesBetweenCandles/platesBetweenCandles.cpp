// binary search
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> pos;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '|')
                pos.push_back(i);
        }        
        vector<int> ans;
        for (auto q: queries) {
            int l = std::lower_bound(pos.begin(), pos.end(), q[0]) - pos.begin(), r = std::upper_bound(pos.begin(), pos.end(), q[1]) - pos.begin() - 1;
            if (l < r) {
                ans.push_back(pos[r] - pos[l] - (r - l + 1) + 1);
            }
            else ans.push_back(0);
        }
        return ans;
    }
};

// left & right
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) 
    {
        int n = s.size();
        vector<int>presum(n);
        int count = 0;
        for (int i=0; i<n; i++)
        {
            count += (s[i]=='*');
            presum[i] = count;
        }
        
        vector<int>last(n);
        int t = -1;
        for (int i=0; i<n; i++)
        {            
            if (s[i]=='|')
                t = i;
            last[i] = t;
        }
        
        vector<int>next(n);
        t = n;
        for (int i=n-1; i>=0; i--)
        {
            if (s[i]=='|')
                t = i;
            next[i] = t;            
        }
        
        vector<int>rets;
        for (auto q: queries)
        {
            int a = q[0], b = q[1];
            int x = next[a], y = last[b];
            
            if (x<=y && x>=a && y<=b)
                rets.push_back(presum[y] - presum[x]);
            else
                rets.push_back(0);
        }
        
        return rets;
    }
};