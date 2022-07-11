class Solution {
public:
    int X=2048;
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int a[4096];
        int n=people.size();
        vector<vector<int>>ans(n,vector<int>(2));
        sort(people.begin(),people.end(),[&](vector<int>&x,vector<int>&y)->bool{return x[0]<y[0]||(x[0]==y[0]&&x[1]>y[1]);});
        int i,j,k,l;
        //对线段树进行初始化，a[i]表示以i为根的树中空座位数量
        for(i=2,k=X,l=1;i<=X*2;i<<=1,k>>=1)for(j=i/2;j--;)a[l++]=k;
        //逐个找座位
        for(i=0;i<n;i++){
            for(j=1,k=people[i][1];j<X;--a[j]){
                j<<=1;
                if(k>=a[j])k-=a[j++];
            }
            ans[j-X]=people[i];
        }
        return ans;
    }
};

// https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/onlogncshuang-bai-jie-fa-shu-zhuang-shu-zu-28ms11m/


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 排序
        sort(people.begin(), people.end(),
                [](const vector<int>& lhs, const vector<int>& rhs)
                 {return lhs[0] == rhs[0] ? lhs[1] <= rhs[1] : lhs[0] > rhs[0];});
        int len = people.size();
        list<vector<int>> tmp;
        // 循环插入
        for(int i = 0; i < len; ++i){
            auto pos = tmp.begin();
            advance(pos, people[i][1]);
            tmp.insert(pos, people[i]);
        }
        // 重建vector返回
        return vector<vector<int>>(tmp.begin(), tmp.end());
    }
};

// sort
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] == b[0]? a[1] >= b[1]: a[0] < b[0];
        });
        int n = people.size();
        vector<vector<int> > ans(n);
        for (auto &v: people) {
            int h = v[1];
            for (int i = 0; i < n; ++i) {
                if (!ans[i].size()) {
                    if (h) --h;
                    else {
                        ans[i] = v;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
