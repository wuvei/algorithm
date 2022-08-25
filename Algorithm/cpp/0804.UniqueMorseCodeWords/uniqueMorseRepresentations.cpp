class Solution {
public:
    const string MORSE[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        for (auto &w: words) {
            string temp = "";
            for (auto c: w) {
                temp += MORSE[c - 'a'];
            }
            s.insert(std::move(temp));
        }
        return s.size();
    }
};