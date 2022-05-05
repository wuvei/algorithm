class MyHashSet {
public:
    MyHashSet() {
        hash = vector<bool>(1000007, false); 
    }
    
    void add(int key) {
        hash[key] = true;
    }
    
    void remove(int key) {
        hash[key] = false;
    }
    
    bool contains(int key) {
        return hash[key];
    }
private:
    vector<bool> hash;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// bitmap as bucket
class MyHashSet {
public:
    MyHashSet() {
        hash = vector<int>(31252, 0);
    }
    
    void add(int key) {
        hash[key / 32] |= (1 << (key % 32));
    }
    
    void remove(int key) {
        hash[key / 32] &= (~((1 << (key % 32))));
    }
    
    bool contains(int key) {
        return hash[key / 32] & ((1 << (key % 32)));
    }
private:
    vector<int> hash;
};


class MyHashSet {
public:
    int hash(int key) {
        int i = key % len;
        for (; data[i] != -2 && data[i] != key; i = (i == len - 1)? 0: i + 1);
        return i;
    }
    MyHashSet() {
        data = vector<int>(len, -2);
    }
    
    void add(int key) {
        data[hash(key)] = key;
    }
    
    void remove(int key) {
        data[hash(key)] = -1;
    }
    
    bool contains(int key) {
        return data[hash(key)] == key;
    }
private:
    int len = 13333;     // 10000 / 0.75
    vector<int> data;
};
