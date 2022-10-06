class Solution {
public:
    // 时间复杂度O(n)，空间复杂度O(1)
    vector<int> threeEqualParts(vector<int> &arr) {
        int n = arr.size(), ones = std::accumulate(arr.begin(), arr.end(), 0), lastZeros = 0;

        for (int i = n - 1; i >= 0 && arr[i] == 0; --i) {
            ++lastZeros;
        }
        if (!ones) {
            return vector<int> {0, n - 1};
        }
        if (ones % 3) {
            return vector<int> {-1, -1};
        }
        ones /= 3;
        vector<int> divides;
        for (int i = 0, countOnes = 0, countZeros = 0; i < n && divides.size() < 2;) {
            countOnes = 0, countZeros = 0;
            while (countOnes < ones) {
                countOnes += arr[i++];
            }
            while (countZeros < lastZeros) {
                if (!arr[i++]) {
                    ++countZeros;
                }
                else {
                    return vector<int> {-1, -1};
                }
            }
            divides.emplace_back(i);
        }
        for (int i = divides[0] - 1, j = divides[1] - 1, k = n - 1;
                i >= 0 && j >= divides[0] && k >= divides[1]; --i, --j, --k) {
            if (arr[i] == arr[j] && arr[j] == arr[k]) {
                continue;
            }
            return {-1, -1};
        }
        divides[0] -= 1;
        return divides;
    }
};
// https://leetcode.cn/problems/three-equal-parts/solution/-by-muse-77-dper/