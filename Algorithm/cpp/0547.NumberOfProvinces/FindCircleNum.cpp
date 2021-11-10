#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> uni;
public:
    int find(int a) {
        int temp = a;
        while(uni[a] != -1) a = uni[a];
        while(uni[temp] != -1) {
            int z = temp;
            temp = uni[temp];
            uni[z] = a;
        }
        return a;
    }
    void Union(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa != fb) uni[fb] = fa;
    }
    int findCircleNum(vector<vector<int> >& isConnected) {
        int n = isConnected.size(), ret = 0;
        uni.resize(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    Union(i, j);
                    // cout << "i: " << i << ", j: " << j << ", uni: ";
                    // for (int e: uni) cout << e << " ";
                    // cout << endl;
                }
            }
        }
        for (int i: uni) {
            if (i == -1) ret++;
        }
        return ret;
    }
};

int main(){
    vector<vector<int> > v(3, vector<int>(3, 1));
    Solution s;
    int ret = s.findCircleNum(v);
    cout << "ret: " << ret << endl;
    return 0;
}