class Solution {
public:
    int coef = 0, consant = 0;
    string cur = "";
    bool if_plus = true, if_left = true;
    inline int getVal(bool if_x) {
        if (cur == "") {
            if (if_x)
                return if_plus ? 1 : -1;
            else return 0;
        }
        int temp = stoi(cur);
        cur = "";
        if (!if_plus) return -temp;
        return temp;
    } 
    string solveEquation(string equation) {
        for (char c: equation) {
            if (c == '+' || c == '-') {
                int temp = getVal(false);
                if (temp)
                    consant += if_left ? -temp : temp;
                if_plus = (c == '+');
            }
            else if (c == '=') {
                consant += -1 * getVal(false);
                if_left = false;
                if_plus = true;
            }
            else if (c == 'x') {
                int temp = getVal(true);
                coef += if_left ? temp : -temp;
            }
            else {
                cur += c;
            }
        }
        consant += getVal(false);
        if (!coef && !consant)
            return "Infinite solutions";
        if (!coef && consant)
            return "No solution";
        return "x=" + to_string(consant / coef);
    }
};