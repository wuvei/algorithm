class Solution {
public:
    int minOperations(string s) {
        int eq = 0;
        string b = "01";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == b[i & 1])
                ++eq;
        }
        return std::min(eq, static_cast<int>(s.size() - eq));
    }
};