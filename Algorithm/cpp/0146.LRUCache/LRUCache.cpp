class LRUCache {
public:
    LRUCache(int capacity): cap(capacity) {
        cache.clear();
        pos.clear();
    }
    
    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;
        cache.splice(cache.begin(), cache, it -> second);
        return it -> second -> second;
    }
    
    void put(int key, int value) {
        auto it = pos.find(key);
        if (pos.find(key) != pos.end()) {
            it -> second -> second = value;
            return cache.splice(cache.begin(), cache, it -> second);
        }
        cache.push_front({key, value});
        pos[key] = cache.begin();
        if (cache.size() > cap) {
            pos.erase(cache.back().first);
            cache.pop_back();
        }
    }
private:
    int cap;
    list<pair<int, int> > cache;
    unordered_map<int, list<pair<int, int> >::iterator> pos;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */