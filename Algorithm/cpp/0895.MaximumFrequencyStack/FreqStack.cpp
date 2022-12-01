class FreqStack {
private:
    unordered_map<int, int> count;
    unordered_map<int, vector<int> > m;
    int max_freq;
public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        ++count[val];
        if (count[val] > max_freq) {
            max_freq = count[val];
            m[max_freq] = {val};
        }
        else m[count[val]].push_back(val);
    }
    
    int pop() {
        vector<int> &v = m[max_freq];
        int e = v.back();
        v.pop_back();
        --count[e];
        if (v.size() == 0) {
            --max_freq;
        }
        return e;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */