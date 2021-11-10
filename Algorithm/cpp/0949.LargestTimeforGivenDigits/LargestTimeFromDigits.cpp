#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        string str;
        if(arr[1] > 5 || arr[0] > 2 || (arr[0] == 2 && arr[1] > 3))
            return str;
        for(int i=2;i>=0;i--){
            vector<int> arr1 = arr;
            auto it = std::find (arr1.begin(), arr1.end(), i);
            if(it!=arr1.end()){
                str.append(to_string(i));
                arr1.erase(it);
                if(i==2){
                    for(int j=3;j>=0;j--){
                        auto it2 = std::find (arr1.begin(), arr1.end(), j);
                        if(it2!=arr1.end()){
                            str.append(to_string(j)+":");
                            arr1.erase(it2);
                            break;
                        }
                    }
                    
                }
                else{
                    str.append(to_string(arr1[arr1.size()-1])+":");
                    arr1.erase(arr1.end()-1);
                }
                if(arr1[1]<=5){
                    str.append(to_string(arr1[1]));
                    str.append(to_string(arr1[0]));
                    break;
                }
                else if(arr1[0]<=5){
                    str.append(to_string(arr1[0]));
                    str.append(to_string(arr1[1]));
                    break;
                }
                else {
                    str.clear();
                }
            }
        }
        return str;
    }

    void ff(vector<int> &arr1, int large, string &str) {
        for(int i = large; i >= 0; i--) {
            auto it = std::find(arr1.begin(), arr1.end(), i);
            if (it != arr1.end()) {
                arr1.erase(it);
                str += to_string(i);
                break;
            }
        }
    }
    string largestTimeFromDigits2(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        string str;
        if(arr[1] > 5 || arr[0] > 2 || (arr[0] == 2 && (arr[1] > 3 || arr[2] > 5)))
            return str;
        int helper[3] = {};
        for (int e: arr) {
            if (e <= 5)
                helper[2]++;
            if (e <= 3)
                helper[1]++;
            if (e == 2)
                helper[0]++;
        }
        vector<int> arr1(arr);
        if (helper[0] >= 1 && helper[1] >= 2 && helper[2] >= 3) {
            auto it = std::find(arr1.begin(), arr1.end(), 2);
            arr1.erase(it);
            str += to_string(2);
            ff(arr1, 3, str);
            str += ":";
        }
        else {
            ff(arr1, 1, str);
            str += to_string(arr1[arr1.size() - 1]) + ":";
            arr1.erase(arr1.end() - 1);
        }
        if(arr1[1] <= 5) {
            str.append(to_string(arr1[1]) + to_string(arr1[0]));
        }
        else {
            str.append(to_string(arr1[0]) + to_string(arr1[1]));
        }
        return str;
    }
};

int main() {
    vector<int> a {0, 0, 0, 0};
    Solution s;
    string ret = s.largestTimeFromDigits2(a);
    cout << ret << endl;
    return 0;
}