class Solution {
public:
    void op(vector<string> &cani, string &s) {
        if (s != "") {
            if (s == "..") {
                if (cani.size()) cani.pop_back();
            }
            else if (s != ".") cani.push_back(s);
        }
        s = "";
    }
    string simplifyPath(string path) {
        vector<string> cani;
        string s;
        for (char c: path) {
            if (c == '/') op(cani, s);
            else s += c;
        }
        op(cani, s);
        if (!cani.size()) return string("/");
        string ret;
        for (string str: cani)
            ret += "/" + str;
        return ret;
    }
};

// Actually a stack can be used