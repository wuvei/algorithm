class MyStack {
private:
    queue<int> que;
public:
    MyStack() {}
    
    void push(int x) {
        que.push(x);
        for (int i = 0; i < que.size() - 1; i++) {            
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int top = que.front();
        que.pop();
        return top;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};

// 作者：richard-az
// 链接：https://leetcode-cn.com/problems/implement-stack-using-queues/solution/by-richard-az-1k2h/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class MyStack {
private:
    queue<int> q1, q2;
public:
    MyStack() {}
    
    void transfer() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
    }
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        transfer();
        int top = q1.front();
        q1.pop();
        swap(q1, q2);
        return top;
    }
    
    int top() {
        transfer();
        return q1.front();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};