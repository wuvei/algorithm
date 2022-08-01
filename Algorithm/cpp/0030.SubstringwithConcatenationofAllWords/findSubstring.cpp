class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordNum = words.size(), wordLen = words[0].size(), len = s.size();
        unordered_map<string, int> m;
        vector<int> ans;
        for (auto &w: words) ++m[w];
        for (int i = 0; i < wordLen; ++i) {
            unordered_map<string, int> m2;
            int num = 0;
            for (int j = i; j < len - wordLen * wordNum + 1; j += wordLen) {
                bool hasremoved = false;
                while (num < wordNum) {
                    string word = s.substr(j + num * wordLen, wordLen);
                    if (m.find(word) != m.end()) {
                        ++m2[word];
                        if (m2[word] > m[word]) {
                            hasremoved = true;
                            int removeNum = 0;
                            while (m2[word] > m[word]) {
                                string firstWord = s.substr(j + removeNum * wordLen, wordLen);
                                --m2[firstWord];
                                ++removeNum;
                            }
                            num = num - removeNum + 1;
                            j += (removeNum - 1) * wordLen;
                            break;
                        }
                    }
                    else {
                        m2.clear();
                        j += num * wordLen;
                        num = 0;
                        break;
                    }
                    ++num;
                }

                if (num == wordNum)
                    ans.push_back(j);

                if (num > 0 && !hasremoved) {
                    string firstWord = s.substr(j, wordLen);
                    --m2[firstWord];
                    --num;
                }
            }
        }
        return ans;
    }
};

// https://leetcode.wang/leetCode-30-Substring-with-Concatenation-of-All-Words.html