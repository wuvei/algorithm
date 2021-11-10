#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    inline bool f(int num) {
        return num < 26 && num > 9;
    }
    int translateNum(int num) {
        if (num < 10) return 1;
        int last[2] = {1, 1}, ind = 1;
        last[0] = f(num % 100) ? 2 : 1;
        string numStr = to_string(num);
        for (int i = numStr.size() - 3; i >= 0; i--) {
            last[ind] = last[(ind + 1) % 2] + (f(stoi(numStr.substr(i, 2))) ? last[ind] : 0);
            ind = (ind + 1) % 2;
            //cout << last[0] << " " << last[1] << endl;
        }
        return last[(ind + 1) % 2];
    }
};

int main() {
    Solution s;
    cout << s.translateNum(506);
    return 0;
}