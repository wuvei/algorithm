class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;
        bool con[5]{};
        string sym = "!@#$%^&*()-+";
        unordered_set<char> special(sym.begin(), sym.end());
        con[0] = true;
        char prev = ' ';
        for (char c: password) {
            if (c == prev) return false;
            if (std::islower(c)) con[1] = true;
            else if (std::isupper(c)) con[2] = true;
            else if (std::isdigit(c)) con[3] = true;
            else if (special.count(c)) con[4] = true;
            prev = c;
        }
        for (bool b: con)
            if (!b) return false;
        return true;
    }
};