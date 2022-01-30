class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while(x){
            result = 10 * result + x % 10;
            x = x / 10;
        }
        return ( result > INT_MAX || result < INT_MIN) ? 0 : result;
    }
};