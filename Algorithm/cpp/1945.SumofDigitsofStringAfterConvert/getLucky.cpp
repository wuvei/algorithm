class Solution {
public:
    int getLucky(string s, int k) {
        string ans = "";
        ans.reserve(s.length() << 1);
        for(int i = 0;i < s.length(); ++i) {
            ans += to_string(s[i] - 'a' + 1);
        }
        int sum = 0;
        while(k--) {
            for(int i = 0; i < ans.length(); ++i) {
               sum += ans[i] - '0';
            }
           ans = std::to_string(sum);
           sum = 0;
        }
        return stoi(ans);
    }
};