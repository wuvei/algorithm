#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string card = "345678910JKQA2";
    vector<string> v;
    
    // 处理大小王
    v.push_back("joker JOKER");
    v.push_back("JOKER joker");
    
    // 输入
    string input;
    while(getline(cin, input)) {
        // 分左右手
        size_t pos = input.find('-');
        // 将牌分开
        string s1(input.begin(), input.begin() + pos), s2(input.begin() + pos + 1, input.end());
        
        // 计数左右手空格数
        int n1 = count(s1.begin(), s1.end(), ' '), n2 = count(s2.begin(), s2.end(), ' ');
        
        // 遇见王炸直接输出
        if(s1 == v[0] || s1 == v[1]) {
            cout << s1 << endl;
            continue;  // 跳出这次循环，执行下一次
        }
        if(s2 == v[0] || s2 == v[1]) {
            cout << s2 << endl;
            continue;
        }
        
        // 个子，对子，三个一样的，四个一样的均可比较
        // 因为这里的牌是排好序的
        if(n1 == n2) {
            cout << (card.find(s1[0]) > card.find(s2[0]) ? s1 : s2) << endl;
            continue;
        }
        
        // 炸弹和不是炸弹的牌
        if(n1 == 3 && n2 != 3) {
            cout << s1 << endl;
            continue;
        }
        else if(n1 != 3 && n2 == 3) {
            cout << s2 << endl;
            continue;
        }
        cout << "ERROR" << endl;
    }
    return 0;
}

// https://blog.csdn.net/weixin_43967449/article/details/106846346
