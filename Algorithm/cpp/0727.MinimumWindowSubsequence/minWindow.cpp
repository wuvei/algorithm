class Solution {
public:
    /**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
    string minWindow(string &S, string &T) {
        int s = S.size(), t = T.size();
        vector<vector<int>> dp(s, vector<int>(t, -1));
        if (S[0] == T[0]) dp[0][0] = 0;
        for(int i = 1; i < s; i++)
            if (S[i] == T[0])
                dp[i][0] = i;
            else dp[i][0] = dp[i - 1][0];

        for(int i = 1; i < s; i++) {
            for(int j = 1; j < t; j++) {
                if(S[i] == T[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int begin = -1, length = INT_MAX;
        for(int i = 0; i < s; i++) {
            int index = dp[i][t-1];
            if(index != -1) {
                int curLength = i - index + 1;
                if(curLength < length) {
                    begin = index;
                    length = curLength;
                }
            }
        }
        if(begin == -1)
            return "";
        return S.substr(begin, length);
    }
};


// next ch after pos: state machine
class Solution {
public:
    /**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
    string minWindow(string &S, string &T) {
        int m = S.size();
        vector<vector<int> > next(m, vector<int>(26, -1));
        for (int i=m-2; i>=0; i--)
        {
            for (int ch=0; ch<26; ch++)
                next[i][ch] = next[i+1][ch];
            next[i][S[i + 1]-'a'] = i+1;
        }
        vector<int>start;
        for (int i=0; i<m; i++)
        {
            if (S[i]==T[0])
                start.push_back(i);
        }
        T = T.substr(1);
        int l = -1, len = INT_MAX;
        
        for (int i: start)
        {
            int j = i;
            int flag = 1;
            for (auto ch: T)
            {
                j = next[j][ch-'a'];
                if (j==-1)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                int temp = j-i+1;
                if (len > temp)
                {
                    l = i;
                    len = temp;
                }
            }        
        }
        return l == -1? "": S.substr(l, len);
    }
};