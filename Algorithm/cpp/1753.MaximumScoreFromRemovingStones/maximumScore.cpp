class Solution {
public:
    int maximumScore(int a, int b, int c) {
    	// recursively makesure a >= b and a >= c
    	if(a < b)
    		return maximumScore(b, a, c);
    	if(a < c)
    		return maximumScore(c, b, a);
        
		return (b + c) <= a ? b + c : (a + b + c) >> 1;
    }
};