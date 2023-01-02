class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        long long tot = 0;
        for (int p: piles) {
            pq.push(p);
            tot += p;
        }
        while (k--) {
            int t = pq.top(), minus = t >> 1;
            pq.pop();
            tot -= minus;
            pq.push(t - minus);
        }
        return static_cast<int>(tot);
    }
};