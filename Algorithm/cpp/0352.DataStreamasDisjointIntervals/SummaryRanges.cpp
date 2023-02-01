class SummaryRanges {
public:
    void addNum(int val) {
        if (m.count(val)) return;
        const int lo = lowerKey(val), hi = higherKey(val);
        
        // {lo, m[lo]} + val + {hi, m[hi]} = {lo, m[hi]}
        if (lo >= 0 && hi >= 0 && m[lo] + 1 == val && val + 1 == hi) {
            m[lo] = m[hi];
            m.erase(hi);
        // {lo, m[lo]} + val = {lo, val}
        // (prevent adding duplicate entry by using '>=' instead of '==')
        } else if (lo >= 0 && m[lo] + 1 >= val) {
            m[lo] = max(m[lo], val);
        } else if (hi >= 0 && val + 1 == hi) {
        // val + {hi, map[hi]} = {val, map[hi]}
            m[val] = m[hi];
            m.erase(hi);
        } else {
            m[val] = val;
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        ans.reserve(m.size());
        for (const auto &it : m)
            ans.push_back({it.first, it.second});
        return ans;
    }

private:
    map<int, int> m;    // {start: end}

    // maximum in m < key
    int lowerKey(int key) {
        const auto it = m.lower_bound(key);  // minimum in m >= key
        if (it == m.cbegin())
            return -1;
        return std::prev(it)->first;
    }

    // minimum in m > key
    int higherKey(int key) {
        const auto it = m.upper_bound(key);  // minimum in m > key
        if (it == m.cend())
            return -1;
        return it->first;
    }
};


/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */