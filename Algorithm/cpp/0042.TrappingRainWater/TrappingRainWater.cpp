class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;

        int length = height.size(), left = 0, right = length - 1, leftMax = height[0], rightMax = height[right], volume = 0;
        
        while (left < right)
        {
            if (leftMax < rightMax) {
                volume += leftMax - height[left++];
                leftMax = max(height[left], leftMax);
            }
            else {
                volume += rightMax - height[right--];
                rightMax = max(height[right], rightMax);
            }
        }
        return volume;
    }

    int trap2(vector<int>& height) {
        int l = 0, r = height.size() - 1, water = 0, minHeight = 0;
        while (l < r) {
            while (l < r && height[l] <= minHeight) {
                water += minHeight - height[l++];
            }
            while (l < r && height[r] <= minHeight) {
                water += minHeight - height[r--];
            }
            minHeight = min(height[l], height[r]);
        }
        return water;
    }
    
    // 0ms
    int trap3(vector<int>& height) {
        int res = 0;
        for(int i = 0 ; i < height.size(); i++){
            if(this->bars.empty() || height[this->bars.top()] >= height[i]){
                bars.push(i);
            }else{
                while(!this->bars.empty() && height[this->bars.top()]<height[i]){
                    int currBar = height[this->bars.top()];
                    this->bars.pop();
                    if(this->bars.empty())
                        break;
                    int barH = min(height[this->bars.top()],height[i]) - currBar;
                    int barL = i - this->bars.top() - 1;
                    res += barH * barL;
                    // this->bars.pop();

                }
                this->bars.push(i);
            }
        }
        return res;
    }
private:
    stack<int> bars;
};