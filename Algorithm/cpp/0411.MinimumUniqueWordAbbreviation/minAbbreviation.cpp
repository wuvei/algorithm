class Solution {
public:
    /**
     * @param target: a target string 
     * @param dictionary: a set of strings in a dictionary
     * @return: an abbreviation of the target string with the smallest possible length
     */
    string minAbbreviation(string &target, vector<string> &dictionary) {
        int n = target.size();
        unordered_set<string> dict;
        for (auto s: dictionary) {
            if (s.size() == n) dict.insert(s);
        }
        vector<pair<int, int> > abbr;
        for(int i = 0; i < (1<<n); i++) abbr.push_back({getLen(i, n), i});
        sort(abbr.begin(), abbr.end());
        
        for (auto p: abbr) {
            int mask = p.second, flag = 1;
            string t = getAbbr(mask, target);
            for (string s: dict) {
                if (t == getAbbr(mask, s)) {
                    flag = 0;
                    break;
                }
            }
            if (flag) return t;
        }
        return "";
    }
    string getAbbr(int mask, string &s) {
        string ret;
        int n = s.size(), i = n - 1, count0 = 0;
        for (; i >= 0 && mask > 0; i--, mask = mask >> 1) {
            if((mask & 1) == 1) {
                if (count0 > 0) {
                    ret = to_string(count0) + ret;
                    count0 = 0;
                }
                ret = s[i] + ret;
            }
            else count0++;
        }
        if (i >= 0) ret = to_string(1 + i) + ret;
        return ret;
    }
    int getLen(int mask, int n) {
        int result = 0, flag = 0, i = n - 1;
        for (; i >= 0 && mask > 0; i--, mask = mask >> 1) {
            if((mask & 1) == 1) {
                result++;
                if (flag) result++;
                flag = 0;
            }
            else flag = 1;
        }
        if (i >= 0) result++;
        return result;
    }
};