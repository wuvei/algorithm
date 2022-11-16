class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pqb.push(num);
        pqs.push(pqb.top());
        pqb.pop()a;
        if (pqs.size() > pqb.size()) {
            pqb.push(pqs.top());
            pqs.pop();
        }
    }
    
    double findMedian() {
        if (pqs.size() != pqb.size()) {
            return pqb.top();
        }
        else return (pqb.top() + pqs.top()) / 2.0;
    }
private:
    priority_queue<int> pqb;
    priority_queue<int, vector<int>, greater<int> > pqs;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */