#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 一开始就直接做一次翻转
        reverse(s.begin(), s.end());

        int n = s.size();
        // 当前遍历的位置
        int i = 0;
        // 实际字符的位置
        int l = 0;

        cout << s << endl << endl;
        while (i < n)
        {
            // 忽略空格
            if (s[i] != ' ')
            {
                cout << "s[" << i << "] " << s[i] << " l " << l << endl;
                cout << s << endl << endl;
                // 如果是第一个单词无需加空格，如果是第二个或后续的单词，则额外附加一个空格
                if (l != 0)
                {
                    s[l] = ' ';
                    ++l;
                }
                // 遍历当前的单词直到遇到空格
                // 临时保存当前l的起点来用于后续翻转使用
                int prevL = l;
                while (i < n && s[i] != ' ')
                {
                    s[l] = s[i];
                    ++l;
                    ++i;
                }
                reverse(s.begin() + prevL, s.begin() + l);
            }
            else
            {
                ++i;
            }
        }
        // 清楚后续被忽略的内容
        cout << l << " " << n << " " << s << endl;
        s.erase(s.begin() + l, s.end());
        return s;
    }

    string reverseWords2(string s) {
        int l, r = s.size() - 1;
        string ret;
        while(r >= 0){
            while(r >= 0 && s[r] == ' ') --r; // clear spaces
            if(r < 0) break;
            for(l = r; l >= 0 && s[l] != ' '; --l); // fetch word
            ret += (s.substr(l + 1, r - l) + " ");
            r = l;
        }
        if(ret.size()) ret.pop_back();
        return ret;
    }
};

int main() {
    string a("The  sky is blue.  ");
    Solution s;
    cout << s.reverseWords(a) << endl;
    return 0;
}