class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, vector<string> > g;
        unordered_set<string> visit(bank.begin(), bank.end());
        if (visit.find(end) == visit.end()) return -1;
        auto f = [&](string &str) {
            for (auto &s: bank) {
                if (str == s) continue;
                int cnt = 0;
                for (int i = 0; i < s.size(); ++i) {
                    if (str[i] != s[i]) ++cnt;
                    if (cnt > 1) break;
                }
                if (cnt == 1)
                    g[str].push_back(s);
            }
        };
        for (auto &s: bank) f(s);
        f(start);
        queue<string> q;
        visit.clear();
        q.push(start);
        visit.insert(start);
        int ans = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                string s = q.front();
                q.pop();
                if (s == end) return ans;
                for (auto &next: g[s]) {
                    if (visit.find(next) == visit.end()) {
                        q.push(next);
                        visit.insert(next);
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};