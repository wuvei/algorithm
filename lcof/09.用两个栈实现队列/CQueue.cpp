class CQueue {
public:
    CQueue() {
        stack<int>().swap(a);
        stack<int>().swap(b);
    }
    
    void appendTail(int value) {
        a.push(value);
    }
    
    int deleteHead() {
        int ret = -1;
        if (!b.empty()) {
            ret = b.top();
            b.pop();
        }
        else if (!a.empty()) {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
            ret = b.top();
            b.pop();
        }
        return ret;
    }

private:
    stack<int> a, b;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */