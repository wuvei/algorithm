// Divide and Conquer
class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) return {1};
        else if (n == 2) return {1, 2};
        m[1] = {1};
        m[2] = {1,2};
        return recur(n);
    }

    vector<int> recur(int n) {
        if (m.find(n) != m.end()) return m[n];
        vector<int> v(n);
        int i = 0;
        for (int num: recur((n + 1) / 2))
            v[i++] = 2 * num - 1;
        for (int num: recur(n / 2))
            v[i++] = 2 * num;
        m[n] = v;
        return v;
    }
private:
    map<int, vector<int> > m;
};

// DP
class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) return {1};
        else if (n == 2) return {1, 2};
        vector<vector<int> > dp(n + 1);
        dp[1] = {1};
        dp[2] = {1, 2};
        for (int i = 3; i <= n; i++) {
            vector<int> temp(i);
            int j = 0;
            for (int num: dp[(i + 1) / 2])
                temp[j++] = 2 * num - 1;
            for (int num: dp[i / 2])
                temp[j++] = 2 * num;
            dp[i] = temp;
        }
        return dp[n];
    }

};

// sort on bit
class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans(n);
        for(int i=0; i<n; i++)
            ans[i] = i+1;

        auto cmp = [=](int a, int b)
        {
            int i = 1;
            while((a&i)==(b&i))
                i = i<<1;
            return  (a&i) < (b&i);
        };

        sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};

// https://leetcode-cn.com/problems/beautiful-array/solution/zhe-shi-shuang-100de-da-an-c-by-jameswan-jo0r/
// https://leetcode-cn.com/problems/beautiful-array/solution/kan-liao-yi-xia-da-shen-de-dai-ma-shuo-yi-xia-zi-j/
