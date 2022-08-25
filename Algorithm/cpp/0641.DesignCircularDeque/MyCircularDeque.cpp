class MyCircularDeque {
private:
    int _max_size, _head = 0, _tail = -1, _size = 0;
    vector<int> _data;
public:
    MyCircularDeque(int k): _max_size(k), _data(k) {}
    
    bool insertFront(int value) {
        if (_size == _max_size)
            return false;
        if (!_size) {
            _data[0] = value;
            _head = _tail = 0;
        }
        else {
            _head = (_head) ? _head - 1 : _max_size - 1;
            _data[_head] = value;
        }
        ++_size;
        return true;
    }
    
    bool insertLast(int value) {
        if (_size == _max_size)
            return false;
        if (!_size) {
            _data[0] = value;
            _head = _tail = 0;
        }
        else {
            _tail = (_tail == _max_size - 1) ? 0 : _tail + 1;
            _data[_tail] = value;
        }
        ++_size;
        return true;
    }
    
    bool deleteFront() {
        if (!_size) return false;
        _head = (_head == _max_size - 1) ? 0 : _head + 1;
        --_size;
        return true;
    }
    
    bool deleteLast() {
        if (!_size) return false;
        _tail = (_tail == 0) ? _max_size - 1 : _tail - 1;
        --_size;
        return true;
    }
    
    int getFront() {
        if (!_size) return -1;
        return _data[_head];
    }
    
    int getRear() {
        if (!_size) return -1;
        return _data[_tail];
    }
    
    bool isEmpty() {
        return !_size;
    }
    
    bool isFull() {
        return _size == _max_size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */