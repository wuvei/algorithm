// bitset -> string, reverse -> bitset -> ulong
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);
        string temp = b.to_string();
        reverse(temp.begin(), temp.end());
        return bitset<32>(temp).to_ulong();
    }
};

// https://leetcode.com/problems/reverse-bits/discuss/1723115/2-0ms-CPP-Solution
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<32;i++){
              if((n & (1 << i)))
                 ans |= 1 << ((31) - i);
        }
        return ans;
    }
};

class Solution {
public:
     uint32_t reverseBits(uint32_t n) {
        uint32_t reverse=0; int flag{0};
        if(n==0) return n;
        while(n){
            reverse<<=1;
            reverse|=(n&1);
            n>>=1;
            flag++;
        }
        return reverse<<=(32-flag);
    }
};