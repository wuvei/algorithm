class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int e: arr) {
            ++m[e];
        }
        unordered_set<int> s;
        for (auto [k, v]: m) {
            if (!s.insert(v).second) 
                return false;

        }
        return true;
    }
};