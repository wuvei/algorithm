class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        string ans(n1 + n2, ' ');
        for (int idx = 0, i = 0, j = 0; i < n1 || j < n2;) {
            if (i < n1) ans[idx++] = word1[i++];
            if (j < n2) ans[idx++] = word2[j++];
        }
        return ans;
    }
};