/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

template < typename BipreT >
    class Bipre {
        /**
         * @author daydayUppp
         * @brief core : sum[l][r] = sum[l][r-1] + sum[l-1][r] - sum[l-1][r-1] + g[l][r]
         * @attention
         */
        public: BipreT ** pre; // 记 pre[l][r] 表示 (0,0) -> (l-1,r-1) 的一个前缀和
        int n,
        m; // 长宽
        BipreT sumRegion(int r1, int c1, int r2, int c2) {
            // 返回 (r1,c1) 为左上角 (r2,c2) 为右下角 的子矩阵的和
            // 左上角一般不会有问题 对右下角做一个处理
            r2 = min(r2, n - 1), c2 = min(c2, m - 1);
            return pre[r2 + 1][c2 + 1] - pre[r1][c2 + 1] - pre[r2 + 1][c1] + pre[r1][c1];
        }
        Bipre(vector < vector < BipreT >> & g,
            const BipreT Init_v) {
            n = g.size(), m = g[0].size();
            pre = new BipreT * [n + 1];
            for (int i = 0; i <= n; i++) pre[i] = new BipreT[m + 1];
            // 初始化 pre
            for (int i = 0; i <= n; i++) pre[i][0] = Init_v;
            for (int j = 1; j <= m; j++) pre[0][j] = Init_v;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + g[i - 1][j - 1];
                }
            }
        }
        ~Bipre() {
            delete[] pre;
        }
    };
class Solution {
    public: int n;
    Bipre < int > * h;
    Node * dfs(vector < vector < int >> & grid, int a, int b, int c, int d) {
        // (a,b) 左上角 (c,d) 右下角
        // 整个区域的大小为 : (c - a + 1) * (c - a + 1)
        Node * res;
        int sum = (c - a + 1) * (c - a + 1);
        int t = h -> sumRegion(a, b, c, d);
        if (!t) { // 全是 0
            res = new Node(0, 1);
        } else if (t == sum) { // 全是 1
            res = new Node(1, 1);
        } else {
            res = new Node(1, 0);
            res -> topLeft = dfs(grid, a, b, (a + c) / 2, (b + d) / 2);
            res -> topRight = dfs(grid, a, (b + d) / 2 + 1, (a + c) / 2, d);
            res -> bottomLeft = dfs(grid, (a + c) / 2 + 1, b, c, (b + d) / 2);
            res -> bottomRight = dfs(grid, (a + c) / 2 + 1, (b + d) / 2 + 1, c, d);
        }
        return res;
    }
    Node * construct(vector < vector < int >> & grid) {
        n = grid.size();
        h = new Bipre < int > (grid, 0); // 二维前缀和
        return dfs(grid, 0, 0, n - 1, n - 1);
    }
};

// 作者： daydayUppp🎈
// 链接： https: //leetcode.cn/problems/construct-quad-tree/solutions/1456963/daydayuppp-by-daydayuppp-nuey/
//     来源： 力扣（ LeetCode）
// 著作权归作者所有。 商业转载请联系作者获得授权， 非商业转载请注明出处。