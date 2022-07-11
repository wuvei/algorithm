class Solution {
public:
    string countAndSay(int n) {
        string a[] = {"1", "11", "21", "1211"};
        if (n <= 4) return a[n - 1];
        string prev = "1211";
        for (int i = 5; i <= n; ++i) {
            string curr = "";
            int start = 0;
            int pos = 0;

            while (pos < prev.size()) {
                while (pos < prev.size() && prev[pos] == prev[start]) {
                    pos++;
                }
                curr += to_string(pos - start) + prev[start];
                start = pos;
            }
            prev = curr;
        }
        
        return prev;
    }
};