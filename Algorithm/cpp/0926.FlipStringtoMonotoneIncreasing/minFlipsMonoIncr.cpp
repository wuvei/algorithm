class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0, ones = 0;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == '1')
                ++ones;
            else
                ++ans;
            ans = std::min(ones, ans);
        }   
        return ans;
    }
};