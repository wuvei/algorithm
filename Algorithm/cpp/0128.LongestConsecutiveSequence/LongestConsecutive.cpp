class Solution {
private:
    unordered_set<int> s;
public:
    int longestConsecutive(vector<int>& nums) {
        for(int n: nums)
            s.insert(n);
        int longgest = 0;
        for(int n: s) {
            if (s.count(n - 1)) continue;
            int count = 1;
            while (s.count(n + 1)) {
                count++;
                n++;
            }
            if (longgest < count) longgest = count; 
        }
        return longgest;
    }
};


class Solution {
private:
    unordered_map<int, int> dict;
public:
    int longestConsecutive(vector<int>& nums) {
        int longgest = 0;
        for (int n: nums) {
            if (!dict.count(n)) {
                int left = dict.count(n - 1)? dict[n - 1]: 0;
                int right = dict.count(n + 1)? dict[n + 1]: 0;
                int length = 1 + left + right;
                if (length > longgest) longgest = length;
                dict[n] = 1;
                dict[n - left] = length;
                dict[n + right] = length;
            }
        }
        return longgest;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int ans = 0;
        while (!hash.empty()) {
            int cur = *(hash.begin());
            hash.erase(cur);
            int next = cur + 1, prev = cur - 1;
            while (hash.count(next)) hash.erase(next++);
            while (hash.count(prev)) hash.erase(prev--);
            ans = max(ans, next - prev - 1);
        }
        return ans;
    }
};