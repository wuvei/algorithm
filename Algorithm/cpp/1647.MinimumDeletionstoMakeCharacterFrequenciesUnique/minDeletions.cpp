class Solution {
public:
    int minDeletions(string s) {
        int count[26] = {};
        for (char c: s)
            count[c - 'a']++;
        sort(count, count + 26, greater<int>());
        int ans = 0, prev = count[0];
        for (int i = 1; i < 26 && count[i] > 0; ++i) {
            if (prev <= count[i]) {
                if (prev > 0) --prev;
                ans += count[i] - prev;
            }
            else prev = count[i];
        }
        return ans;
        
    }
};