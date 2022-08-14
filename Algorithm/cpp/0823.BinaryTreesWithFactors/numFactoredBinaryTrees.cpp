class Solution {
public:
    static constexpr int mod = static_cast<int>(1e9) + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> m;
        long long ans = 0;
        for (int num: arr) {
            long long ways = 1;
            double lim = sqrt(num);
            for (int i=0, childA = arr[0]; childA <= lim; childA = arr[++i]) {
                if (num % childA != 0)
                    continue;
                int childB = num / childA;
                if (m.find(childB) != m.end())
                    ways += m[childA] * (m[childB] << (childA == childB ? 0 : 1));
            }
            m[num] = ways % mod;
            ans = (ans + ways) % mod;
        }
        
        return ans;
    }
};
