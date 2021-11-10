class Solution {
public:
    int nthUglyNumber(int n) {
        int *arr = new int[n];
        arr[0] = 1;
        int *pMultiply2 = arr, *pMultiply3 = arr, *pMultiply5 = arr, nextIdx = 1;
        while (nextIdx < n) {
            int currentMin = min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
            arr[nextIdx] = currentMin;
            while(*pMultiply2 * 2 <= currentMin) 
                pMultiply2++;
            while (*pMultiply3 * 3 <= currentMin)
                pMultiply3++;
            while (*pMultiply5 * 5 <= currentMin)
                pMultiply5++;
            nextIdx++;
        }
        return arr[n - 1];
    }
};