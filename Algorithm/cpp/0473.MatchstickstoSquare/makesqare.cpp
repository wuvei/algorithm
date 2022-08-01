// backtracking on 'bucket'
class Solution {
public:
    vector<int> nums; 
    vector<bool> st;
    int len;
    bool makesquare(vector<int>& matchsticks) 
    {
        nums = matchsticks;
        st.resize(nums.size(), false); 
        len = accumulate(nums.begin(), nums.end(), 0);
        if((len & 3) != 0) return false;
        len >>= 2;
        sort(nums.begin(), nums.end(), greater<int>());   // 剪枝1 -- 火柴长度从大到小排序
        return dfs(0, 0, 0); 
    }

    // start 参数表示从那个编号的火柴开始搜, 剪枝2 --  防止重复, 保证在每条边内火柴编号递增
    bool dfs(int start, int cur, int cnt) {
        if(cnt == 3) return true; 
        if(cur == len) return dfs(0, 0, cnt + 1); 
        for(int i = start; i < nums.size(); ++i) {
            if(st[i]) continue; 
            if(cur + nums[i] <= len) {
                st[i] = true;
                if(dfs(start + 1, cur + nums[i], cnt)) return true; 
                st[i] = false;
            }
			
            // 剪枝3: 第一根 / 最后一根失败 
            if(!cur || cur + nums[i] == len) return false; 
            
            // 剪枝3: 跳过相同长度
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i; 
        }
        return false; 
    }
};


// 作者：xie-dai-ma-de-huo-che
// 链接：https://leetcode.cn/problems/matchsticks-to-square/solution/by-xie-dai-ma-de-huo-che-lyxs/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


// backtracking on balls
class Solution {
public:
    bool dfs(int index, vector<int> &matchsticks) {
        if (index == matchsticks.size())
            return true;
            
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < i; ++j) {
                if (edges[j] == edges[i])
                    goto jj;
            }
            edges[i] += matchsticks[index];
            if (edges[i] <= len && dfs(index + 1, matchsticks)) {
                return true;
            }
            edges[i] -= matchsticks[index];
            jj: continue;
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks) {
        len = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if ((len & 3) != 0)
            return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 减少搜索量
        len >>= 2;
        return dfs(0, matchsticks);
    }
private:
    int edges[4] = {}, len;
};