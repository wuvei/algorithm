class MyCircularQueue {
public:
    MyCircularQueue(int k): size(k), data(k), len(0), front(0), back(-1) {
    }
    
    bool enQueue(int value) {
        if (len == size) {
            return false;
        }
        back = back == size - 1 ? 0 : back + 1;
        data[back] = value;
        ++len;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = front == size - 1 ? 0 : front + 1;
        --len;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[back];
    }
    
    bool isEmpty() {
        return !len;
    }
    
    bool isFull() {
        return len == size;
    }
private:
    vector<int> data;
    int size, len, front, back;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */