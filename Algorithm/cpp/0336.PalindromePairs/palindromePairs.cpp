// Hash
class Solution {
public:
    bool f(string& s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> words_index_map;
        set<int> word_size_set;
        int n = words.size();
        for(int i = 0; i < n; ++i) {
            words_index_map[words[i]] = i;
            word_size_set.insert(words[i].size());
        }
        vector<vector<int>> res;
        for(int i = 0; i < words.size(); ++i){
            string word_reverse = words[i];
            reverse(word_reverse.begin(), word_reverse.end());
            
            if(words_index_map.count(word_reverse) && words_index_map[word_reverse] != i){
                res.push_back({words_index_map[word_reverse], i});
            }
            int length = word_reverse.size();

            for(auto it = word_size_set.begin(); *it != length; it++){
                int d = *it;
                if(f(word_reverse, 0, length - d - 1) && 
                    words_index_map.count(word_reverse.substr(length - d))){
                    res.push_back({i, words_index_map[word_reverse.substr(length - d)]});
                }
                if(f(word_reverse, d, length - 1) && 
                    words_index_map.count(word_reverse.substr(0, d))){
                    res.push_back({words_index_map[word_reverse.substr(0, d)], i});
                }
            }
            
        }
        return res;
    }
};

// 作者：wang-yan-19
// 链接：https://leetcode.cn/problems/palindrome-pairs/solution/guan-fang-de-da-an-kan-de-wo-tou-teng-hao-shi-da-b/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。