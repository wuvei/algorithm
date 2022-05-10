// dfs
class Solution {
public:
    void dfs(int ind) {
        if (ind == ch.size()) {
            ans.push_back(string(ch.begin(), ch.end()));
            return;
        }
        for (char c: v[str[ind] - '0']) {
            ch[ind] = c;
            dfs(ind + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return ans;
        ch.resize(digits.size());
        this -> str = digits;
        dfs(0);
        return ans;
    }
private:
    string str;
    vector<string> ans;
    vector<char> ch;
    vector<vector<char> > v = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
};

// queue simulate
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return {};
        }//提交了发现24/25，空字符没处理，leetcode细节滴神
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        queue <string> result;
        int length_of_queue=1;
        //记录数组长度，便于后续pop全部的元素
        result.push("");
        //开始给一个空string用于往后面加东西
        
        for(int i=0;i<digits.length();i++){
                //遍历数组
            for(int k=0;k<length_of_queue;k++){
                string a = result.front(); 
                result.pop();
                    //记录并pop队列
                for(int j=0;j<phoneMap[digits[i]].length();j++){
                    string c=a+phoneMap[digits[i]][j];
                        //向队列加入新的数字对应的字符
                    result.push(c);
                            //加入后入queue
                }
                
            }
            length_of_queue*=phoneMap[digits[i]].length();
            //别忘了维护queue长度

        }
        vector <string >a;
        while(!result.empty()){
            a.push_back(result.front());
            result.pop();
        }//queue改个vector
        //cout<<length_of_queue;
        return a;

    }
};

// 作者：what-for-h
// 链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/solution/0ms-by-what-for-h-yv5o/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。