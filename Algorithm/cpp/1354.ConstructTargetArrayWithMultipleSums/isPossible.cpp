// https://leetcode.cn/problems/construct-target-array-with-multiple-sums/solution/duo-ci-qiu-he-gou-zao-mu-biao-shu-zu-by-leetcode-s/
class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;
        priority_queue<int> pq;
        long long total = 0;
        for (int e: target) {
            pq.push(e);
            total += e;
        }
        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if (x == 1) break;
            if (x + x - total < 1)
                return false;
            long long left = total - x, y = pq.top(), k;
            if (y == 1) k = (x - y + left - 1) / left;
            else k = (x - y) / left + 1;
            x -= k * left;
            if (x <= 0) return false;
            total -= k * left;
            pq.push(x);
        }
        return true;
    }
};


// https://leetcode.cn/problems/construct-target-array-with-multiple-sums/solution/cni-tui-you-xian-dui-lie-by-monologue-s-dcso/
class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<long long> q;
        for(int ev: target){
            sum += ev;
            q.push(ev);
        }
        while(q.top() != 1){
            long long curMax = q.top(); q.pop();
            long long otherSum = sum - curMax;
            if(curMax - otherSum < 1 || otherSum == 0) return false;
            long long temp = curMax % otherSum;
            if(temp == 0) temp = otherSum;
            q.push(temp);
            sum = sum - curMax + temp;
        }
        return true;
    }
};