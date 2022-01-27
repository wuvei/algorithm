// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(1){
            int num = rand7() * 7 -rand7() + 1;
            if (num < 41) return num % 10 + 1;
            num = (num - 40) * 7 - rand7() + 1;
            if (num < 61) return num % 10 + 1;
            num = (num - 60) * 7 - rand7() + 1;
            if (num < 21) return num % 10 + 1;
        }
    }
};