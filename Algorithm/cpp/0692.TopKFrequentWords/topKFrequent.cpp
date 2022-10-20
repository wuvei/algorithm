class Solution {
public:
    using pp = unordered_map<string, int>::iterator;
    vector<string> topKFrequent(vector<string>& words, int k) {
        function<bool(pp &a, pp &b)> cmp = [](pp &a, pp &b) -> bool {
            return a->second == b->second ? a->first < b->first : a->second > b->second;
        };
        priority_queue<pp, vector<pp>, function<bool(pp &a, pp &b)> > pq(cmp);
        unordered_map<string, int> m;
        for (string &w : words) {
            ++m[w];
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            pq.push(it);
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> ans;
        ans.reserve(k);
        while (!pq.empty()) {
            ans.push_back(pq.top()->first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};