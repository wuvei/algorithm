class Solution {
    public: double maxAverageRatio(vector < vector < int >> & classes, int extraStudents) {
        auto profit = [ & ](double pass, double total) {
            return (pass + 1) / (total + 1) - pass / total;
        };
        double total = 0;
        priority_queue < pair < double, int >> pq;
        int n = classes.size();
        for (int i = 0; i < n; ++i) {
            total += static_cast < double > (classes[i][0]) / classes[i][1];
            pq.push({
                profit(classes[i][0], classes[i][1]),
                i
            });
        }
        while (extraStudents--) {
            auto[added_profit, id] = pq.top();
            pq.pop();
            total += added_profit;
            ++classes[id][0];
            ++classes[id][1];
            pq.push({
                profit(classes[id][0], classes[id][1]),
                id
            });
        }
        return total / n;
    }
};