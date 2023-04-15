class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int fact[26], idx;
        memset(fact, -1, sizeof(fact));
        for (int i = 0; i < s.size(); ++i) {
            idx = s[i] - 'a';
            if (fact[idx] == -1) fact[idx] = i;
            else if (i - fact[idx] - 1 != distance[idx])
                return false;
        }
        return true;
    }
};