#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int getSum(int x){
        int sum = 0;
        while(x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    int movingCount(int m, int n, int k) {
        queue<pair<int, int> > q;
        bool *visited = new bool[m * n];
        memset(visited, 0, m * n);
        int dirx[] = {0, 0, 1, -1}, diry[] = {1, -1, 0, 0};
        q.push(make_pair(0, 0));
        int num = 1;
        visited[0] = true;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int exp_x = p.first + dirx[i], exp_y = p.second + diry[i];
                if (exp_x >= 0 && exp_x < m && exp_y >= 0 && exp_y < n && !visited[exp_x * n + exp_y] && getSum(exp_x) + getSum(exp_y) <= k) {
                    q.push(make_pair(exp_x, exp_y));
                    visited[exp_x * n + exp_y] = true;
                    num++;
                }
            }
        }
        delete []visited;
        return num;
    }
};

int main() {
    Solution s;
    cout << s.movingCount(2, 3, 1) << endl;
    return 0;
}