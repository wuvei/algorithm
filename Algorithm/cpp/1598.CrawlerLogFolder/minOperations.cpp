class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step = 0;
        for (auto &s: logs) {
            if (s == "../") {
                if (step > 0) {
                    --step;
                }
            }
            else if (s != "./") {
                ++step;
            }
        }
        return step;
    }
};