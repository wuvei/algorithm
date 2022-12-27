class Solution {
public:
    int takeCharacters(string s, int k) {
        int count[3] = {};
        for (char c: s)
            ++count[c - 'a'];
        for (int i = 0; i < 3; ++i) {
            if (count[i] < k) return -1;
            count[i] -= k;
        }
        int ans = 0, nums[3] = {};
        for (int l = 0, r = 0; r < s.size(); ++r) {
            int idx = s[r] - 'a';
            ++nums[idx];
            while (nums[idx] > count[idx]) {
                --nums[s[l] - 'a'];
                ++l;
            }
            ans = std::max(ans, r - l + 1);
        }
        return s.size() - ans;
    }
};