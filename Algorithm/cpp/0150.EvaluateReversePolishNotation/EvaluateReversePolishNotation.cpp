#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto it: tokens) {
            if (it == "*" || it == "-" || it == "+" || it == "/") {
                int operand1 = s.top();
                s.pop();
                int operand2 = s.top();
                s.pop();
                if (it == "*") s.push(operand2 * operand1);
                else if (it == "-") s.push(operand2 - operand1);
                else if (it == "+") s.push(operand2 + operand1);
                else if (it == "/") s.push(operand2 / operand1);
            }
            else {
                s.push(stoi(it));
            }
        }
        return s.top();
    }
};

int main() {
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution sol;
    cout << sol.evalRPN(tokens) << endl;
    return 0;
}