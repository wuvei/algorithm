#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int cycle_time = 2 * numRows - 2;
        vector<string> result(numRows);
        for(int i = 0; i < s.size(); i++){
            int temp = i % cycle_time;
            int row = temp >= numRows ? (cycle_time - temp) : temp;
            result[row] += s[i];
        }
        string finalResult = "";
        for (string substr : result){
            finalResult += substr;
        }
        return finalResult;
    }
};

int main(){
    Solution sol;
    cout << sol.convert("PAYPALISHIRING", 3) << endl;
    cout << sol.convert("PAYPALISHIRING", 4) << endl;
    cout << sol.convert("a", 1) << endl;
    return 0;
}