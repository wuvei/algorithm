class Solution {
public:
    int getInt(char c) {
        switch (c) {
            case 'a': return 16;
            case 'e': return 8;
            case 'i': return 4;
            case 'o': return 2;
            case 'u': return 1;
            default: return 0;
        }
    }
    
    int findTheLongestSubstring(string s) {
        int pre = 0, ans = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < s.size(); i++) {
            pre = pre ^ getInt(s[i]);
            if (m.count(pre)) ans = std::max(ans, i - m[pre]);
            else m[pre] = i;
        }
        return ans;
    }
};