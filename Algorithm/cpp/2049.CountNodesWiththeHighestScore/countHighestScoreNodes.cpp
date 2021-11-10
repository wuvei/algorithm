class Solution {
public:
    int treeSize(int node) {
        if (child.find(node) == child.end()) {
            subTreeSize[node] = 1;
            return 1;
        }
        int temp = 1;
        for (int n: child[node]) {
            temp += treeSize(n);
        }
        subTreeSize[node] = temp;
        return temp;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int nums = parents.size();
        child.clear();
        subTreeSize.resize(nums, 0);
        for (int i = 1; i < nums; i++) {
            if (child.find(parents[i]) == child.end())
                child[parents[i]] = vector<int>({i});
            else child[parents[i]].push_back(i);
        }
        treeSize(0);
        long long highest_score = 0;
        int count = 0;
        for (int i = 0; i < nums; i++) {
            long long temp = 1;
            int left = nums - 1;
            if (child.find(i)!= child.end()) {
                for (int n: child[i]) {
                    temp *= subTreeSize[n];
                    left -= subTreeSize[n];
                }
            }
            temp *= left == 0? 1: left;
            if (temp == highest_score) count++;
            else if (temp > highest_score) {
                highest_score = temp;
                count = 1;
            }
        }
        return count;
    }
private:
    unordered_map<int, vector<int> > child;
    vector<int> subTreeSize;
};