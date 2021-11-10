class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0, Fnum = 0, Tnum = 0, ans = 0, n = answerKey.size();
        for (int i = 0; i < n; i++) {
            if (answerKey[i] == 'T') Tnum++;
            else Fnum++;
            if (Tnum > k && Fnum > k) {
                if (answerKey[l++] == 'T') Tnum--;
                else Fnum--;
            }
            ans = std::max(i - l + 1, ans);
        }
        ans = std::max(n - l, ans);
        return ans;
    }
};