class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (!pushed.size()) return true;
        stack<int> s;
        int i = 0, j = 0;
        while (j < popped.size()) {
            while ((s.empty() || s.top() != popped[j]) && i < pushed.size()) s.push(pushed[i++]);
            if (s.top() != popped[j]) return false;
            s.pop();
            j++;
        }
        return true;
    }
};