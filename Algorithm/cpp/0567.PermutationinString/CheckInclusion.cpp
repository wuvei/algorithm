class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int count1[26] = {}, count2[26] = {};
        for (char c: s1) count1[c - 'a']++;
        int start = 0, end = 0, idx;
        while (end < s2.size()) {
            idx = s2[end] - 'a';
            if (count1[idx] > count2[idx]) {
                count2[idx]++;
                end++;
            }
            else if (end - start != s1.size()) {
                count2[s2[start] - 'a']--;
                start++;
            }
            else return true;
        }
        return end - start == s1.size();
    }
};