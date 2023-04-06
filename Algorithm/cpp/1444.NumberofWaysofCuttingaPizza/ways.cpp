typedef long long LL;
typedef pair<int,int> PINT;
typedef vector<PINT> VPINT;
const int inf = 0x7f7f7f7f;	//不能设为7fffffff！容易越界！
const long module = 1e9 + 7;
class Solution {
	static int sum(const PINT& p) { return (p.first + p.second); }
	static PINT minP(const PINT& a, const PINT& b) { return PINT(min(a.first, b.first), min(a.second, b.second)); }
	int rows, cols, acre;	//行数，列数，面积
	VPINT FA;		// FA[idx(row,col)]=(FAR,FAC)
	vector<VPINT > DP;	// DP[idx(row,col)][remain]= <across, vertical>  ；当值为<-1,-1>表示无效记录
	int idx(const int&row, const int&col)const {    //(row,col)二维转一维下标irc
		if (row >= rows || col >= cols)return acre;
		return row*cols + col;
	}
	int idx(const PINT& p)const {return idx(p.first, p.second);}
	//RC=(row,col),以row行col列为左上角的矩形子pizza，切remain刀（按题目要求每一份都要有apple）的切法。
	const PINT& dfs(const PINT& RC, int remain) {
		int irc = idx(RC);
		if (-1 != DP[irc][remain].first)return DP[irc][remain];	//★记忆化递归——记录有效，直接查表★
		//切0刀的（remain==0）的情况全都写好在 DP[][0] 中了！
		PINT nRC = FA[idx(RC.first + 1, RC.second)];
		int across = ((LL)(nRC.first - RC.first)*sum(dfs(nRC, remain - 1))+ dfs(nRC, remain).first) % module;
		nRC = FA[idx(RC.first, RC.second+1)];
		int vertical = ((LL)(nRC.second - RC.second)*sum(dfs(nRC, remain - 1))+ dfs(nRC, remain).second) % module;
		return DP[irc][remain] = PINT(across, vertical);	//★记忆化递归——记录！★
	}
public:
	int ways(vector<string>& pizza, int k) {
		rows = pizza.size(); cols = pizza[0].length(); acre = rows*cols;
		DP.reserve(acre + 1);	DP.resize(acre, VPINT(k, PINT(-1, -1)));
		DP.push_back(VPINT(k, PINT(0, 0)));	//多出的1个空间用于返回(row,col)越界时的结果——0种切法
		FA.resize(acre + 1);	FA[acre] = PINT(inf, inf);	//坐标越界设为无穷（只要大于rows,cols即可）
		for (int r = rows; r-- > 0;) {
			for (int c = cols; c-- > 0;) {
				FA[idx(r, c)] = ('A' == pizza[r][c]) ? PINT(r, c) : minP(FA[idx(r + 1, c)], FA[idx(r, c + 1)]);
				if (FA[idx(r, c)].first != inf) {DP[idx(r, c)][0] = PINT(1, 0);}	//子pizza[r:,c:]含有apple，切0刀算1种
			}
		}
		return sum(dfs(FA[0], k - 1));
	}
};

// 作者：java_Lee
// 链接：https://leetcode.cn/problems/number-of-ways-of-cutting-a-pizza/solutions/241055/ji-yi-hua-di-gui-bu-xu-yao-guan-dpci-xu-rong-yi-xi/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。