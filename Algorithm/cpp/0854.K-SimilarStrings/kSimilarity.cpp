// DFS
class Solution {
private:
    int result = INT_MAX, len;
public:
    int kSimilarity(string s1, string s2) {
        len = s1.size();
        int count = 0;
        for (int i = 0, j = 0; i < len; ++i, j = i) {
            if (s1[i] != s2[j]) {
                while (++j < len) {
                    if (s1[i] == s2[j] && s1[j] == s2[i]) {
                        ++count;
                        swap(s2[i], s2[j]);
                        break;
                    }
                }
            }
        }
        
        execute(s1, s2, 0, 0);
        return count + result;
    }

    void execute(string s1, string s2, int start, int current) {
        if (current >= result) {
            return;
        }
        if (start == len - 1) {
            if (result > current) {
                result = current;
            }
            return;
        }
        for(int i = start; i < len; i++) {
            if(s1[i] != s2[i]) {
                for(int j = i + 1; j < len; j++) {
                    if(s2[j] == s1[i] && s1[j] != s2[j]) {
                        swap(s2[i], s2[j]);
                        execute(s1, s2, i + 1, current + 1);
                        swap(s2[i], s2[j]);
                    }
                }
                return;
            }
        }
        if (result > current) {
            result = current;
        }
    }
};