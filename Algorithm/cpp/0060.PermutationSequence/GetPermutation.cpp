#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) return string("1");
        int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector<char> ch = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string ret;
        int i;
        for (i = n; i > 2; i--) {
            int quotient = k / factorial[i - 1];
            int remainder = k % factorial[i - 1];
            if (!remainder) quotient--;
            ret += ch[quotient];
            ch.erase(ch.begin() + quotient);
            k = remainder;
            if (!k) break;
            // cout << "i = " << i << ", quotient = " << quotient << ", add char: " << ret.back() << endl;
            // cout << "ch: ";
            // for (char c: ch) cout << c << " ";
            // cout << endl;
        }
        if (!k) {
            for (i--; i > 0; i--) {
                ret += ch[i - 1];
            }
        }
        else if (k == 1) ret += string({ch[0], ch[1]});
        else ret += string({ch[1], ch[0]});
        return ret;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector<char> ch = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string ret;
        k--;
        for (int i = n - 1; i >= 0; i--) {
            int quotient = k / factorial[i];
            ret += ch[quotient];
            ch.erase(ch.begin() + quotient);
            k -= quotient * factorial[i];
        }
        return ret;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector<bool> visited(n, false);
        string ret;
        for (int i = n - 1; i >= 0; i--) {
            int cnt = factorial[i];
            for (int j = 1; j <= n; j++) {
                if (visited[j]) continue;
                if (k > cnt) {
                    k -= cnt;
                    continue;
                }
                visited[j] = true;
                ret += to_string(j);
                break;
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    string re = s.getPermutation(6, 129);
    cout << "Results: " << re << endl;
    return 0;
}