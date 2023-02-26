class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int suit_cnt[4]{}, cnt1 = 0;
        for (char e: suits) {
            int idx = e - 'a';
            if (++suit_cnt[idx] > cnt1)
                cnt1 = suit_cnt[idx];
        }
        if (cnt1 == 5) return "Flush";
        int rank_cnt[14]{}, cnt2 = 0;
        for (int e: ranks) {
            if (++rank_cnt[e] > cnt2)
                cnt2 = rank_cnt[e];
        }
        if (cnt2 >= 3) return "Three of a Kind";
        else if (cnt2 == 2) return "Pair";
        return "High Card";
    }
};