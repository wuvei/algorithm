class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int length = a.size();
        if (length < 2) return vector<int>(a);
        vector<int> ret(length, 1);
        for (int i = 1; i < length; i++)
            ret[i] *= a[i - 1] * ret[i - 1];
        int temp = 1;
        for (int i = length - 2; i >= 0; i--) {
            temp *= a[i + 1];
            ret[i] *= temp;
        }
        return ret;
    }
};