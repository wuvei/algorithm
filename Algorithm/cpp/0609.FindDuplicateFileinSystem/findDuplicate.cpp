class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for (auto &p: paths) {
            stringstream s(p);
            string path, file;
            s >> path;
            while (s >> file) {
                auto pos = file.find("(");
                string temp = "";
                temp.reserve(path.size() + file.size());
                temp.append(path);
                temp.append("/");
                temp.append(file.substr(0, pos));
                string content = file.substr(pos + 1);
                mp[content].push_back(std::move(temp));
            }
        }
        vector<vector<string>> ans;
        for (auto &it: mp) {
            if (it.second.size() > 1) {
                ans.push_back(std::move(it.second));
            }
        }
        return ans;
    }
};