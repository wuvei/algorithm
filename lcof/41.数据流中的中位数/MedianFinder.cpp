class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(maxHeap.size() == minHeap.size()) {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();   
        }
        else {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop(); 
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else return maxHeap.top();
    }

    
    void addNum2(int num) {
        if (maxHeap.size() == 0 && minHeap.size() == 0) {
            maxHeap.push(num);
            return;
        }
        if(maxHeap.size() == minHeap.size()) {
            if (maxHeap.top() > num) maxHeap.push(num);
            else minHeap.push(num);   
        }
        else if (maxHeap.size() > minHeap.size()) {
            if (maxHeap.top() <= num) minHeap.push(num);
            else {
                maxHeap.push(num);
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else {
            if (maxHeap.top() >= num) maxHeap.push(num);
            else {
                minHeap.push(num);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian2() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else return maxHeap.size() > minHeap.size() ? maxHeap.top(): minHeap.top();
    }
private:
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */