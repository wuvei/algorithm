class Solution {
public:
    int longestAwesome(string s) {
        int pre = 0, ans = 1;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < s.size(); i++) {
            pre ^= (1 << (s[i] - '0'));
            for (int j = 0; j < 10; j++) {
                int temp = 1 << j, target = pre ^ temp;
                if (m.count(target)) ans = std::max(i - m[target], ans);
            }
            if (m.count(pre)) ans = std::max(i - m[pre], ans);
            else m[pre] = i;
        }
        return ans;
    }
};