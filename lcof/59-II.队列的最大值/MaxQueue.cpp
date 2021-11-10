class MaxQueue {
public:
    MaxQueue() {
        queue<int>().swap(q1);
        deque<int>().swap(dq);
        deque<int>().swap(dq2);
    }
    
    int max_value() {
        if (q1.empty()) return -1;
        return dq.front();
    }
    
    void push_back(int value) {
        q1.push(value);
        int temp = 1;
        while (!dq.empty() && dq.back() < value) {
            dq.pop_back();
            temp += dq2.back();
            dq2.pop_back();
        }
        dq.push_back(value);
        dq2.push_back(temp);
    }
    
    int pop_front() {
        if (q1.empty()) return -1;
        int ret = q1.front();
        q1.pop();
        dq2[0]--;
        if (dq2[0] == 0) {
            dq2.pop_front();
            dq.pop_front();
        }
        return ret;
    }
private:
    queue<int> q1;
    deque<int> dq, dq2;
};


class MaxQueue {
public:
    MaxQueue() {
        queue<int>().swap(q1);
        deque<int>().swap(dq);
    }
    
    int max_value() {
        if (q1.empty()) return -1;
        return dq.front();
    }
    
    void push_back(int value) {
        q1.push(value);
        while (!dq.empty() && dq.back() < value) dq.pop_back();
        dq.push_back(value);
    }
    
    int pop_front() {
        if (q1.empty()) return -1;
        int ret = q1.front();
        q1.pop();
        if (dq[0] == ret) dq.pop_front();
        return ret;
    }
private:
    queue<int> q1;
    deque<int> dq;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */