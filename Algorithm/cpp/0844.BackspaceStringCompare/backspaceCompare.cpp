// naive
class Solution {
public:
    string eliminateSharp(string &s) {
        string ret;
        for (char c: s) {
            if (c != '#') ret += c;
            else if (ret.size()) ret.pop_back();
        }
        return std::move(ret);
    }
    bool backspaceCompare(string s, string t) {
        return eliminateSharp(s) == eliminateSharp(t);     
    }
};

// two pointers
class Solution {
public:
    int getNext(string &s, int i) {
        int count = 0;
        while (i >= 0) {
            if (s[i] == '#') ++count;
            else if (!count) return i;
            else --count;
            --i;
        }
        return i;
    }
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        while (i >= 0 || j >= 0) {
            i = getNext(s, i);
            j = getNext(t, j);
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;
            }
            else if (i >= 0 || j >= 0) return false;
            --i;
            --j;
        }
        return true;
    }
};