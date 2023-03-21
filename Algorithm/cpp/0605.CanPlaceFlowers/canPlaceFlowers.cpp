class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cont = 1, num = 0;
        for (int e: flowerbed) {
            if (e) {
                num += std::max((cont - 1) >> 1, 0);
                cont = 0;
            } else ++cont;
        }
        num += cont >> 1;
        return num >= n;
    }
};