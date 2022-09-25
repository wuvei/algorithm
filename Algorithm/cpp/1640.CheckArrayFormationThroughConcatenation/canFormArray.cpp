class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<int> pos(101, -1);
        for (int i = 0; i < pieces.size(); ++i) {
            pos[pieces[i][0]] = i;
        }
        int idx = 0;
        while (idx < arr.size()) {
            int choose = pos[arr[idx]];
            if (choose == -1) {
                return false;
            }
            auto &v = pieces[choose];
            for (int i = 0; i < v.size(); ++i, ++idx) {
                if (v[i] != arr[idx]) {
                    return false;
                }
            }
        }
        return true;
    }
};