class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> max_heap; // <高度, 右端>
        int i = 0, len = buildings.size(), cur_x, cur_h;
        while (i < len || !max_heap.empty()) {
            if (max_heap.empty() || i < len && buildings[i][0] <= max_heap.top().second) {
                cur_x = buildings[i][0];
                while (i < len && cur_x == buildings[i][0]) {
                    max_heap.emplace(buildings[i][2], buildings[i][1]);
                    ++i;
                }
            } else {
                cur_x = max_heap.top().second;
                while (!max_heap.empty() && cur_x >= max_heap.top().second) {
                    max_heap.pop();
                }
            }
            cur_h = (max_heap.empty()) ? 0 : max_heap.top().first;
            if (ans.empty() || cur_h != ans.back()[1]) {
                ans.push_back({cur_x, cur_h});
            }

        }
        return ans;
    }

};


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> height;
        vector<vector<int>> target;
        multiset<int> heap;
        heap.insert(0);
        int cur=0;
        int pre=0;
        for(auto &b : buildings){
            height.push_back({b[0],-b[2]});
            height.push_back({b[1],b[2]});
        }
        sort(height.begin(),height.end());
        for(auto &h : height){
            if(h.second < 0){
                heap.insert(-h.second);
            }else{
                heap.erase(heap.find(h.second));
            }
            cur = *heap.rbegin();
            if(cur != pre){
                target.push_back({h.first,cur});

            }
            pre = cur;
        }
        return target;
    }
};

// 作者：zhao-chun-nian-liu
// 链接：https://leetcode-cn.com/problems/the-skyline-problem/solution/218tian-ji-xian-wen-ti-by-zhao-chun-nian-hazh/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

