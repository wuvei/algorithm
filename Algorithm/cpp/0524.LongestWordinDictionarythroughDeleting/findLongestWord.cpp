// DP / State Machine: f[i][j] j's first appearance after pos i
class Solution
{
public:
	int f[1020][28];

	static bool cmp(string &a, string &b)
	{
		return a.size() == b.size() ? a < b : a.size() > b.size();
	}
	string findLongestWord(string s, vector<string> &dictionary)
	{

		
		int dsz = dictionary.size(), sz = s.size();
		auto &d = dictionary;//引用下，不然数组名字太长不好写。

		/*dp预处理f数组，表示从第i个位置到字符串末尾，j + 'a' 字母的位置*/
		memset(f, -1, sizeof f);
		for (int i = sz - 1; i >= 0; --i)
		{
			for (int j = 0; j < 26; ++j)
				f[i][j] = f[i + 1][j];
			f[i][s[i] - 'a'] = i;
		}

		//按字符串长度从大到小，字典序从小到大排序
		sort(dictionary.begin(), dictionary.end(), cmp);
		for (int i = 0; i < dsz; ++i)
		{
			int ddsz = d[i].size();
			if (sz < ddsz)//单词s长度 比字典中单词还短
				continue;
			
			int j = 0, k = 0;
			for (; k < ddsz; ++k)
			{
				j = f[j][d[i][k] - 'a'] + 1;
				if (!j)// 如果没有这个字符那么 f[i][ans[k] - 'a'] = -1. + 1 后为0 
					break;
			}
			if (k == ddsz)//说明这个单词可以匹配
				return d[i];
		}
		return "";
	}
};

// Double Pointer
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 判断 t 是否是 s 的子序列

        int n = s.size(), m = t.size();
        
        // 如果 t 长度大于 s，一定不是子序列
        if(m > n) return false;

        // 记录当前 s 中匹配到了哪个位置
        int i = 0;
        for(char ch : t) {
            while(i < n && s[i] != ch) i++;
            if(i >= n) return false;

            // 此时 s[i] = ch，下次要从 s[i + 1] 开始匹配
            i++;
        }

        return true;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        // 更长的、字典序更小的排在前面，这样一旦找到，就是结果
        sort(dictionary.begin(), dictionary.end(), [&](string &a, string &b) {
            if(a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });

        for(string &t : dictionary) {
            if(isSubsequence(s, t)) return t;
        }

        // 如果没找到
        return "";
    }
};