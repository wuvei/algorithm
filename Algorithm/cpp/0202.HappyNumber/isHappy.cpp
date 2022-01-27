class Solution {
public:
    bool isHappy(int n) {
        int slow = f(n), fast = f(slow);
        while (slow != fast && fast != 1) {
            slow = f(slow);
            fast = f(f(fast));
        }
        if (fast == 1) return true;
        return false;
    }

    int f(int n) {
        int ans = 0, temp;
        while (n > 0) {
            temp = n % 10;
            ans += temp * temp;
            n /= 10;
        }
        return ans;
    }
};