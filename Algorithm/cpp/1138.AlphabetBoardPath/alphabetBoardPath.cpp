class Solution {
public:
    string getmove(char prev, char c) {
        string ret = "", post = "";
        if (prev == 'z') {
            ret = "U";
            prev = 'u';
        }
        if (c == 'z') {
            post = "D";
            c = 'u';
        }
        int px = static_cast<int>(prev - 'a') / 5, py = static_cast<int>(prev - 'a') % 5;
        int x = static_cast<int>(c - 'a') / 5, y = static_cast<int>(c - 'a') % 5;
        x = std::abs(x - px) * (x - px >= 0 ? 1 : -1);
        y = std::abs(y - py) * (y - py >= 0 ? 1 : -1);
        if (x > 0) ret += string(x, 'D');
        else if (x < 0) ret += string(-x, 'U');
        if (y > 0) ret += string(y, 'R');
        else if (y < 0) ret += string(-y, 'L');
        ret += post;
        return std::move(ret);
    }
    string alphabetBoardPath(string target) {
        char prev = 'a';
        string ans = "";
        for (char c: target) {
            if (prev != c) ans += getmove(prev, c);
            ans += '!';
            prev = c;
        }
        return ans;
    }
};