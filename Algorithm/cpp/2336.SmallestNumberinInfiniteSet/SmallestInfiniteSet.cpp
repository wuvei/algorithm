class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i) 
            pq.push(i);
    }
    
    int popSmallest() {
        int ret = pq.top();
        pq.pop();
        s.emplace(ret);
        return ret;
    }
    
    void addBack(int num) {
        if (s.find(num) != s.end()) {
            pq.push(num);
            s.erase(num);
        }
    }
private:
    priority_queue<int, vector<int>, greater<int> > pq;
    unordered_set<int> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */