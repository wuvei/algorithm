class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<bitset<26> > m;
        for (string &s: words) {
            bitset<26> temp;
            for (char c: s) temp[c - 'a'] = true;
            m.push_back(std::move(temp));
        }

        int n = words.size(), ans = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((m[i] & m[j]) == 0) ans = std::max(ans, int(words[i].size() * words[j].size()));
            }
        }
        return ans;
    }
};

// Opt
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<unsigned int, int> m;
        for (string &s: words) {
            bitset<26> temp;
            for (char c: s) temp[c - 'a'] = true;
            if (m[temp.to_ulong()] < s.size()) m[temp.to_ulong()] = int(s.size());
        }
        int ans = 0;
        for (auto it1 = m.begin(); it1 != m.end(); it1++) {
            for (auto it2 = std::next(it1); it2 != m.end(); it2++) {
                if ((it1->first & it2->first) == 0)
                    ans = std::max(ans, it1->second * it2->second);
            }
        }
        return ans;
    }
};