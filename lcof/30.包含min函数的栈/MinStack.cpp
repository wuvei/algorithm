class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        stack<int>().swap(s1);
        stack<int>().swap(s2);
    }
    
    void push(int x) {
        s1.push(x);
        if (s2.empty()) s2.push(x);
        else s2.push(std::min(x, s2.top()));
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int min() {
        return s2.top();
    }

private:
    stack<int> s1, s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */