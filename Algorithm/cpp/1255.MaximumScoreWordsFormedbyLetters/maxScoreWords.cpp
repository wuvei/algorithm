class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        std::function<int(int, array<int, 26>) > dfs = [&](int i, array<int, 26> cnt) {
            if (i < 0) return 0;
            int ret = dfs(i - 1, cnt);

            int s = 0;
            for (char c: words[i]) {
                if (cnt[c - 'a']-- == 0)
                    return ret;
                s += score[c - 'a'];
            }
            return std::max(ret, s + dfs(i - 1, cnt));
        };
        array<int, 26> cnt{};
        for (char c: letters) ++cnt[c - 'a'];
        return dfs(words.size() - 1, cnt);
    }
};