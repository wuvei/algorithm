class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (int d: data) {
            if (d < 128) {
                if (count) return false;
            }
            else if (d < 192) {
                count--;
                if (count < 0) return false;
            }
            else if (d < 224) {
                if (count) return false;
                count = 1;
            }
            else if (d < 240) {
                if (count) return false;
                count = 2;
            }
            else if (d < 248) {
                if (count) return false;
                count = 3;
            }
            else return false;
        }
        return !count? true: false;
    }
};