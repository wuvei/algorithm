class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if (!tokens.size()) {
            return 0;
        }
        sort(tokens.begin(), tokens.end());
        int ans = 0, score = 0, l = 0, r = tokens.size() - 1;
        while (l <= r) {
            while (l <= r && power >= tokens[l]) {
                ++score;
                power -= tokens[l];
                ++l;
            }
            ans = std::max(ans, score);
            if (!score) {
                break;
            }
            if (l <= r && score > 0) {
                --score;
                power += tokens[r];
                --r;
            }
        }
        return ans;
    }
};