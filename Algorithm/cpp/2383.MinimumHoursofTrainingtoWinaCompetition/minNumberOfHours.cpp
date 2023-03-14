class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        // energy
        int ans = std::max(std::accumulate(energy.begin(), energy.end(), 0) + 1 - initialEnergy, 0), inc;
        // experience
        for (int e : experience) {
            inc = std::max(e + 1 - initialExperience, 0);
            ans += inc;
            initialExperience += e + inc;
        }
        return ans;
    }
};