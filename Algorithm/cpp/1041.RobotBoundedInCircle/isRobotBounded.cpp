class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dist[4]{}, k = 0;
        for (char& c : instructions) {
            if (c == 'L') {
                ++k;
            } else if (c == 'R') {
                k += 3;
            } else {
                ++dist[k];
            }
            if (k >= 4) k -= 4;
        }
        return (dist[0] == dist[2] && dist[1] == dist[3]) || k;
    }
};

// 作者：ylb
// 链接：https://leetcode.cn/problems/robot-bounded-in-circle/solutions/2219798/python3javacgotypescript-yi-ti-yi-jie-mo-cyda/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。