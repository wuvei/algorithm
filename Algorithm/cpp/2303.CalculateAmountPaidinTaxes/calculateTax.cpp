class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int ans = 0, prev = 0;
        for (int i = 0; i < brackets.size() && income > 0; ++i) {
            int t = std::min(brackets[i][0] - prev, income);
            ans += t * brackets[i][1];
            income -= t;
            prev = brackets[i][0];
        }
        return ans / 100.0;
    }
};