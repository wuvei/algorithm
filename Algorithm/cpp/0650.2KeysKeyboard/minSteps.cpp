class Solution {
public:
    int minSteps(int n) {
        int res = 0, m = n;
        for (int i = 2; i <= n; i++) {
            while (m % i == 0) {
                res += i;
                m /= i;
            }
        }
        return res;
    }
};


class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; i++)
        {
            dp[i] = i;
            /* 这里的j不需要写成j <= i，因为判断j是不是因数只要检查到开平方的大小就好了，算是个小优化> */
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                    dp[i] = dp[j] + dp[i / j];
            }
        }

        return dp[n];
    }
};

// 作者：hypnos-2m
// 链接：https://leetcode-cn.com/problems/2-keys-keyboard/solution/c-dong-tai-gui-hua-kan-zhe-ge-jiu-gou-li-ptt9/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 0;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = i;
            if(n % i == 0)
                for(int j = 2; j * j <= i; j++)
                {
                    if(i % j == 0)
                    {
                        dp[i] = min(dp[i], dp[j] + i/j);
                        dp[i] = min(dp[i], dp[i/j] + j);
                    }

                }
        }

        return dp[n];
    }

};