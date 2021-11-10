#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLen = 0, start = -1, recent[128] = {};
        fill(recent, recent + sizeof(recent) / sizeof(int), -1);
        for (int i = 0; i < s.size(); i++)
        {
            if (recent[int(s[i])] != -1)
                start = max(recent[int(s[i])], start);
            recent[int(s[i])] = i;
            maxLen = max(i - start, maxLen);
            cout << "i = " << i << ", start = " << start << ", maxLen = " << maxLen << endl;
        }
        return maxLen;
    }
};

int main() {
    Solution s;
    string ss("abcabcbb");
    int re = s.lengthOfLongestSubstring(ss);
    cout << "max: " << re << endl;
    return 0;
}