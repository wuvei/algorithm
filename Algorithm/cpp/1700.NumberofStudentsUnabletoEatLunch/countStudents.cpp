class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int d[2]{}, eats = 0;
        d[1] = std::accumulate(students.begin(), students.end(), 0);
        d[0] = students.size() - d[1];
        for (int e: sandwiches) {
            if (!d[e])
                return students.size() - eats;
            --d[e];
            ++eats;
        }
        return students.size() - eats;
    }
};