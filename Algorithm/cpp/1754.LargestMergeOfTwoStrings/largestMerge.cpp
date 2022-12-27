class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        string ans(n1 + n2, 'a');
        int i = 0, j = 0, k = 0;
        for (;i < n1 && j < n2; ++k) {
            if (word1[i] > word2[j]) ans[k] = word1[i++];
            else if (word1[i] < word2[j]) ans[k] = word2[j++];
            else {
                if (word1.substr(i) > word2.substr(j)) ans[k] = word1[i++];
                else ans[k] = word2[j++];
            }
        }
        while (i < n1) ans[k++] = word1[i++];
        while (j < n2) ans[k++] = word2[j++];
        return ans;
    }
};