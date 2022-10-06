class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size(), i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && end[j] == 'X') ++j;
            if (i == n || j == n) return i == j;
            if (start[i] != end[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            ++i;
            ++j;
        }
        return i == j;
    }
};