#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void dfs(int segId, int segStart) {
        if (segStart >= length) return;
        // cout << segId << " " << segStart << endl;
        if (segId == 3) {
            if (str[segStart] == '0' && segStart != length - 1) return;
            int lastByte = std::stoi(str.substr(segStart));
            if (lastByte >= 0 && lastByte <= 255) {
                string temp;
                for (int e: segs) {
                    temp += to_string(e) + ".";
                }
                temp += to_string(lastByte);
                addresses.push_back(temp);
                // cout << "segs: ";
                // for (int r: segs) 
                //     cout << r << " ";
                // cout << lastByte << endl;
            }
            return;
        }
        if (str[segStart] == '0') {
            segs.push_back(0);
            dfs(segId + 1, segStart + 1);
            segs.pop_back();
        }
        else {
            for (int i = 1; i <= 3; i++) {
                if (segStart + i >= length) return;
                int nextByte = std::stoi(str.substr(segStart, i));
                // cout << "segs: ";
                // for (int r: segs) 
                //     cout << r << " ";
                // cout << "nextByte: " << nextByte << endl;
                if (nextByte >= 0 && nextByte <= 255) {
                    segs.push_back(nextByte);
                    dfs(segId + 1, segStart + i);
                    segs.pop_back();
                }
            }
        }
        
    }

    vector<string> restoreIpAddresses(string s) {
        addresses.clear();
        segs.clear();
        length = s.size();
        if (length < 4 || length > 12) return addresses;
        str = s;
        dfs(0, 0);
        return addresses;
    }
private:
    vector<string> addresses;
    vector<int> segs;
    string str;
    int length;
};

int main() {
    string str = "25525511135";
    Solution s;
    vector<string> re = s.restoreIpAddresses(str);
    for (string r: re) 
        cout << r << " ";
    cout << endl;
    return 0;
}