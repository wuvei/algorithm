#include <iostream>

using namespace std;

class Solution {
public:
    // Dynamic Programming 
    int cuttingRope(int n) {
        int *table = new int[n + 1];
        table[1] = 1;
        for (int i = 2; i < n; i++) {
            int temp = i;
            for (int j = 1; j <= int(i / 2); j++) {
                temp = max(temp, table[j] * table[i - j]);
            }
            table[i] = temp;
        }
        int re = 0;
        for (int i = 1; i <= int(n / 2); i++)
            re = max(re, table[i] * table[n - i]);
        return re;
    }

    // Greedy
    int cuttingRope2(int n) {
        if (n == 1 || n == 2)
            return 1;
        if (n == 3)
            return 2;
        int sum = 1;
        while (n > 4) {
            sum *= 3;
            n -= 3;
        }

        return sum * n;
    }
    int cuttingRope3(int n) {
        if(n <= 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;       
        int timesOf3 = n / 3;
        if(n % 3 == 1) {
            --timesOf3;
        }
        int timesOf2 = (n - timesOf3 * 3) / 2;
        return pow(3, timesOf3) * pow(2, timesOf2);
    }
};

int main() {
    Solution s;
    cout << s.cuttingRope(10) << endl; 
    return 0;
}