// DP
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> data;
        vector<char> ops;
        int num = 0;
        char op = ' ';
        istringstream ss(expression + "+");
        while (ss >> num && ss >> op) {
            data.push_back(num);
            ops.push_back(op);
        }
        int n = data.size();
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(n, vector<int>()));
        for (int i = 0; i < n; ++i) {
            dp[i][i].push_back(data[i]);
            for (int j = i - 1; j >= 0; --j) {
                for (int k = j; k < i; ++k) {
                    for (auto left: dp[j][k]) {
                        for (auto right: dp[k + 1][i]) {
                            int val = 0;
                            switch (ops[k]) {
                                case '+': val = left + right; break;
                                case '-': val = left - right; break;
                                case '*': val = left * right; break;
                            }
                            dp[j][i].push_back(val);
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};

// Backtracking
class Solution {
public:
    unordered_map<string,vector<int>> mp; //key ：字符串  value: 此串可以构成的所有情况。
    int len;
    //判断串是否可以成为一个数字
    bool check(const string& s){
        if(s.size() == 1) return true;
        else if(s.size() == 2 and  s[0] >= '0' and s[0] <= '9' and s[1] >= '0' and s[1] <= '9') return true;
        return false;
    }
    //递归函数
    void backtrace(string expression){
        if(mp[expression].size() != 0) return;
        if(check(expression)){
            mp[expression].push_back(stoi(expression));
            return;
        }
        for(int i = 0 ; i < (int)expression.size(); i++){
            if(expression[i] < '0' or expression[i] > '9'){
                string left = expression.substr(0, i), right = expression.substr(i+1);
                backtrace(left);
                backtrace(right);
                for(auto &t1 : mp[left]){
                    for(auto &t2 : mp[right]){
                        if(expression[i] == '-') mp[expression].push_back(t1 - t2);
                        else if(expression[i] == '+') mp[expression].push_back(t1 + t2);
                        else mp[expression].push_back(t1 * t2);
                    }
                }
            }
        }
    }
    vector<int> diffWaysToCompute(string expression) {
        len = expression.size();
        backtrace(expression);
        auto ans = vector<int>(mp[expression].begin(), mp[expression].end());
        return ans;
    }
};

// 作者：Tanyf
// 链接：https://leetcode-cn.com/problems/different-ways-to-add-parentheses/solution/tan-tan-zhu-code-c-jie-jin-shuang-bai-hu-a82p/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。