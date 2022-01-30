class Solution {
public:
    int findComplement(int num) {
        long a = 1;
        while(true){
            if(num >= a){
                a <<= 1; // 等价于 a *= 2;
            }else{
                return a - num - 1;
            }
        }
    }
};

class Solution {
public:
    int findComplement(int num) {
        int highbit = 0, ans = 0;
        for(int i = 0; i <= 30; i ++){
            if((1 << i) & num) highbit = i;
        }
        ans = highbit == 30 ? 0x7fffffff: (1 << (highbit + 1)) - 1;
        return ans ^ num;
    }
};