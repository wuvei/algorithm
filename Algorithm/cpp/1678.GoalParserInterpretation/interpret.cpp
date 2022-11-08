class Solution {
public:
    string interpret(string command) {
        string ans;
        ans.reserve(command.size());
        for (int i = 0; i < command.size(); ++i) {
            if (command[i] == 'G')
                ans += "G";
            else if (command[i] == ')') {
                if (command[i - 1] == 'l')
                    ans += "al";
                else ans += "o";
            }
        }
        return ans;
    }
};

class Solution {
public:
    string interpret(string command) {
        while (command.find("()") != -1) command.replace(command.find("()"), 2, "o");
        while (command.find("(al)") != -1) command.replace(command.find("(al)"), 4, "al");
        return command;
    }
};

// 作者：ylb
// 链接：https://leetcode.cn/problems/goal-parser-interpretation/solutions/1951588/by-lcbin-bd63/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。