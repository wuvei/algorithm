class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), w = 0;
        for (int i = 0; i < k; ++i)
            w += blocks[i] == 'W';
        int ans = w;
        for (int i = k, j = 0; i < n; ++i, ++j) {
            w += blocks[i] == 'W';
            w -= blocks[j] == 'W';
            ans = std::min(ans, w);
        }
        return ans;
    }
};