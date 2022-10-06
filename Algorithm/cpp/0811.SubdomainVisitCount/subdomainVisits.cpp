class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count;
        for (string &s: cpdomains) {
            std::string::size_type space_pos = s.find(' '), n;
            int cnt = std::stoi(s.substr(0, space_pos));
            string domain = s.substr(space_pos + 1);
            count[domain] += cnt;
            n = domain.find('.');
            while (n != std::string::npos) {
                count[domain.substr(n + 1)] += cnt;
                n = domain.find('.', n + 1);
            }
        }
        vector<string> ans;
        for (auto &it: count) {
            ans.push_back(std::to_string(it.second) + " " + it.first);
        }
        return ans;
    }
};