#include<iostream>
#include<vector>

using namespace std;
/*
    Greedy: Time Complicity: O(n), Space Complicity: O(1)
    Always calculate the farest index the current index
    could jump to.

*/
class Solution{
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++){
            for(int j = i; j < n - 1 - i; j++){
                int right = j, left = i, pre = matrix[i][j], next;
                for(int k = 0; k < 4; k++){
                    next = matrix[right][n - 1 - left];
                    matrix[right][n - 1 - left] = pre;
                    int temp = right;
                    right = n - 1 - left;
                    left = temp;
                    pre = next;
                }
            }
            
        }
    }
};

int main(){
    int input[][4] = {1,2,3,4,
                    5,6,7,8,
                    9,10,11,12,
                    13,14,15,16};
    vector<vector<int> > arr2(5, vector<int>(5));
    int index=1;
    for(int i = 0; i < arr2.size(); i++)
        for(int j = 0; j < arr2.size(); j++)
            arr2[i][j] = index++;//input[i][j];

    Solution solution;
    for(int i = 0; i < arr2.size(); i++){
        for(int j = 0; j < arr2.size(); j++)
            cout << arr2[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    solution.rotate(arr2);
    for(int i = 0; i < arr2.size(); i++){
        for(int j = 0; j < arr2.size(); j++)
            cout << arr2[i][j] << " ";
        cout << endl;
    }
    return 0;
}