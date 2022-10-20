class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.size() < 26)
            return false;
        int cnt[26]{}, remain = 26;
        for (char c: sentence) {
            if (!cnt[c - 'a']) {
                --remain;
            }
            ++cnt[c - 'a'];
        }
        return remain == 0;
    }
};