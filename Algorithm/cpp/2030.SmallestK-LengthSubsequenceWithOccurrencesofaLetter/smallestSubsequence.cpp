class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        if (k == s.size()) return s;
        if (k == repetition) return string(repetition, letter);
        string ans(s.size(), 'a');
        int letterToDel = std::count(s.begin(), s.end(), letter) - repetition, toDel = s.size() - k, j = 0;
        for (int i = 0; i < s.size(); i++) {
            while(j && toDel && ans[j-1] > s[i]) {
                if (ans[j-1] == letter) {
                    if (!letterToDel) break;
                    else letterToDel--;
                }
                toDel--;
                j--;
            }
            ans[j++] = s[i];
        }
        while (j >= k) {
            if (ans[j--] == letter) letterToDel--;
        }
        for (j = k - 1; letterToDel < 0; j--) {
            if (ans[j] != letter) {
                ans[j] = letter;
                letterToDel++;
            }
        }
        return ans.substr(0, k);
    }
};