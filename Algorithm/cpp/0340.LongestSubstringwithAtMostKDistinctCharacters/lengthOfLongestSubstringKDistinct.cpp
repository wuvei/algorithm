class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        int ans = 0;
        unordered_map<char, int> count;
        for (int l = 0, r = 0; r < s.size(); r++) {
            count[s[r]]++;
            if (count.size() > k) {
                while (count.size() > k) {
                    count[s[l]]--;
                    if (!count[s[l]]) count.erase(s[l]);
                    l++;
                } 
            }
            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }
};