class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int windowSum = 0, s = cardPoints.size() - k;
        for (int i = 0; i < s; ++i)
            windowSum += cardPoints[i];
        int totalSum = windowSum, minSum = windowSum;
        for (int l = 0, i = s; i < cardPoints.size(); ++i, ++l) {
            totalSum += cardPoints[i];
            windowSum += cardPoints[i] - cardPoints[l];
            minSum = std::min(minSum, windowSum);
        }
        return totalSum - minSum;
    }
};

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int windowSum = 0, n = cardPoints.size();
        for (int i = 0; i < k; ++i)
            windowSum += cardPoints[i];
        int maxSum = windowSum;
        for (int i = 0; i < k; ++i) {
            windowSum += cardPoints[n - i - 1] - cardPoints[k - i - 1];
            maxSum = std::max(maxSum, windowSum);
        }
        return maxSum;
    }
};