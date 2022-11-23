class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        auto cross=[](vector<int>&a,vector<int>&b,vector<int>&c){
            return (b[0]-a[0])*(c[1]-b[1])-(b[1]-a[1])*(c[0]-b[0]);
        };
        int n = trees.size();
        if(n < 3) return trees;
        sort(trees.begin(), trees.end());
        vector<vector<int> > low;
        for(auto &p: trees) {
            while(low.size() > 1 && cross(low[low.size() - 1], low[low.size() - 2], p) < 0) low.pop_back();
            low.push_back(p);
        }
        reverse(trees.begin(), trees.end());
        vector<vector<int> > top;
        for(auto &p: trees){
            while(top.size() > 1 && cross(top[top.size() - 1],top[top.size() - 2], p) < 0) top.pop_back();
            top.push_back(p);
        }
        set<vector<int> > s;
        for(auto &p: low) s.insert({p[0],p[1]});
        for(auto &p: top) s.insert({p[0],p[1]});
        return vector<vector<int>>(s.begin(), s.end());
    }
};

// 作者：墨鳌
// 链接：https://leetcode.cn/problems/erect-the-fence/solutions/1292480/mo-ao-tu-bao-suan-fa-by-moao-24t5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。