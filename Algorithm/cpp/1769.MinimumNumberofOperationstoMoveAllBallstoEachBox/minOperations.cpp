class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> cnt(n);
        for (int i = 0, f = 0, prefix = 0; i < n; ++i) {
            cnt[i] += f;
            prefix += (boxes[i] == '1');
            f += prefix;
        }

        for (int i = n - 1, f = 0, prefix = 0; ~i; --i) {
            cnt[i] += f;
            prefix += (boxes[i] == '1');
            f += prefix;
        }

        return cnt;
    }
};