#include <cstdio>
#include <string>
using namespace std;

// Naive
void getNonRepeat1(int num) {
	bool flag;
	while(1) {
		flag = true;
		num++;
		int pre = num % 10, temp = num / 10;
		while(temp) {
			int cur = temp % 10;
			temp = temp / 10;
			if (cur == pre) {
				flag = false;
				break;
			}
			pre = cur;
		}
		if (flag) break;
	}
	printf("%d\n", num);
}

// Naive
void getNonRepeat2(int num) {
	string s = '0' + to_string(num);
	int i = 1, len = s.size();
	bool first = true;
	while (1) {
		while (i + 1 < len && s[i] != s[i + 1]) i++;

		// 原数本身就是一个不重复数，则在其最低位+1
		//+1时进行判断，如果个位为9，则变为0，再进位，否则直接+1 
		//+1后判断会不会跟前一位重复 
		if (i == len - 1 && first) {
			if (s[i] == '9') {
				s[i] = '0';
				i--;
			}
			s[i] += 1;
			i--;
			first = false;
			continue;
		}
		// 不是首次扫描到此，则直接退出，表示当前数为最小不重复数
		else if (i == len - 1) break;

		// 重复的是'99'，此两位置0，高位直接+1
		if (s[i + 1] == '9') {
			s[i] = s[i + 1] = '0';
			s[i - 1] += 1;
			i -= 2;
		}
		else {
			s[i + 1] += 1;
			i += 2;
			bool flag = true;
			while (i < len) {
				if (flag) s[i++] = '0';
				else s[i++] = '1';
				flag = !flag;
			}
			break;
		}
	}

	s[0] == '0'? printf("%s\n", s.substr(1).c_str()) : printf("%s\n", s.c_str());

}
int main()
{
	int num;
	while (scanf("%d", &num) != EOF) {
		getNonRepeat1(num);
		getNonRepeat2(num);
	}
	return 0;
}