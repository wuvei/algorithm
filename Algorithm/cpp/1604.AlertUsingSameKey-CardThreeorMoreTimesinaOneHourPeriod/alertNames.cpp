class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> m;
        for (int i = 0; i < keyName.size(); ++i)
            m[keyName[i]].push_back(std::stoi(keyTime[i].substr(0, 2)) * 60 + std::stoi(keyTime[i].substr(3)));
        vector<string> ans;
        ans.reserve(m.size());
        auto check = [&](vector<int> &v) -> bool {
            sort(v.begin(), v.end());
            for (int l = 0, r = 0; r < v.size(); ++r) {
                while (v[r] - v[l] > 60) ++l;
                if (r - l >= 2) return true;
            }
            return false;
        };
        for (auto &[name, v]: m) {
            if (v.size() > 48) {
                ans.push_back(name);
            }
            else if (check(v)) ans.push_back(name);
        }
        return std::move(ans);
    }
};