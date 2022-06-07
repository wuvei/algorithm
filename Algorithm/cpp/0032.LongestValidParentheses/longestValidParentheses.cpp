// DP
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2) return 0;
        vector<int> dp(s.size(), 0);
        int ans = 0;
        if (s[1] == ')' && s[0] == '(') {
            dp[1] = 2;
            ans = 2;
        }
        for (int i = 2; i < s.size(); ++i) {
            if (s[i] == '(') continue;
            int temp;
            if (s[i - 1] == '(')
                dp[i] = 2 + dp[i - 2];
            else if ((temp = i - 1 - dp[i - 1]) >= 0 && s[temp] == '(') {
                dp[i] = 2 + dp[i - 1];
                if (temp >= 1) dp[i] += dp[temp - 1];
            }
            if (ans < dp[i])
                ans = dp[i];
        }
        return ans;
    }
};

// Stack
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {  // 左括号，入栈下标
                st.push(i);
            } else {               // 右括号
                st.pop();          // 弹出栈顶元素表示匹配了当前右括号
                if (st.empty()) {  // 如果空了，入栈
                    st.push(i);
                } else {  // 如果栈不空，此时的右括号下标-栈顶下标（匹配左下标的前一位）
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};

// 作者：dodo_1202
// 链接：https://leetcode.cn/problems/longest-valid-parentheses/solution/by-dodo_1202-pg7m/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// Two Pointers
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') left++;
            else right++;
            
            if (left == right)
                maxlength = max(maxlength, 2 * right);
            else if (right > left) 
                left = right = 0;
        }
        left = right = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '(') left++;
            else right++;
            
            if (left == right)
                maxlength = max(maxlength, 2 * left);
            else if (left > right)
                left = right = 0;
        }
        return maxlength;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
