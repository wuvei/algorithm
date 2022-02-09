class Solution {
public:
    int gcd(int a, int b) {
      if (a == b) return a;
      if (a & 1) {
        if (b & 1) return gcd(std::abs(a - b), std::min(a, b));
        else return gcd(a, b >> 1);
      }
        else {
        if (b & 1) return gcd(a >> 1, b);
        else return 2 * gcd(a >> 1, b >> 1);
      }
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) return n;
        int ans = 1;

        for (int i = 0; i < n - 1; i++) {
            if (ans >= n - i || ans > n / 2) {
                break;
            }
            int x1 = points[i][0], y1 = points[i][1];
            unordered_map<int, int> m;
            int tempMax = 0;
            for (int j = i + 1; j < n; j++) {
                int x = points[j][0] - x1, y = points[j][1] - y1;
                if (x == 0) y = 1;
                else if (y == 0) x = 1;
                else {
                    if (x < 0) {
                        x = -x;
                        y = -y;
                    }
                    int gcdxy = gcd(std::abs(x), std::abs(y));
                    x = x / gcdxy, y = y / gcdxy;
                }
                int key = x * 20001 + y;
                m[key]++;
                tempMax = std::max(tempMax, m[key]);
            }
            ans = std::max(ans, tempMax + 1);
        }
        return ans;
    }
};