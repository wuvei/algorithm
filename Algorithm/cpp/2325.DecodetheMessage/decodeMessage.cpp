class Solution {
public:
    string decodeMessage(string key, string message) {
        int decode[26]{}, idx = 0;
        memset(decode, ~0, sizeof(decode));
        for (char c: key) {
            if (c != ' ' && decode[c - 'a'] == ~0) {
                decode[c - 'a'] = idx++;
            }
        }
        for (char &c: message) {
            if (c != ' ') {
                c = 'a' + decode[c - 'a'];
            }
        }
        return message;
    }
};