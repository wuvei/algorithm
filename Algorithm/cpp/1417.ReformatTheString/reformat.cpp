class Solution {
public:
    string reformat(string s) {
        string ans = "";
        vector<char> digit, alphabet;
        for (char c: s) {
            if (isdigit(c))
                digit.push_back(c);
            else alphabet.push_back(c);
        }
        int i = 0, d = digit.size(), a = alphabet.size();
        if (abs(d - a) > 1)
            return ans;
        for (; i < d && i < a; ++i) {
            ans += digit[i];
            ans += alphabet[i];
        }
        if (d > a)
            return ans + digit.back();
        else if (d < a)
            return string(1, alphabet.back()) + ans;
        
        return ans;
        
    }
};