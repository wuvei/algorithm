class Solution {
public:
    bool verify(int start, int end, vector<int>& postorder) {
        if (start >= end - 1) return true;
        int h = start, t = end - 1, pivot = postorder[end];
        while (h < end && postorder[h] < pivot) h++;
        while (t >= 0 && postorder[t] > pivot) t--;
        if (h - 1 == t) return verify(start, t, postorder) && verify(h, end - 1, postorder);
        else return false;
    }

    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() < 2) return true;
        return verify(0, postorder.size() - 1, postorder);
    }

    // 单调栈
    bool verifyPostorder2(vector<int>& postorder) {
        if(postorder.size()==0){
            return true;
        }
        stack<int> q;
        int root = INT_MAX;
        for(int i = postorder.size() - 1; i >= 0; i--){
            if(postorder[i] > root){
                return false;
            }
            while(!q.empty() && q.top() > postorder[i]){
                root = q.top();
                q.pop();
            }
            q.push(postorder[i]);
        }
        return true;
    }
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/jian-zhi-offer-33-er-cha-sou-suo-shu-de-hou-xu-b-4/

};