// https://leetcode-cn.com/problems/design-hashmap/solution/706-she-ji-ha-xi-ying-she-by-jyj407-nzcz/

class MyHashMap {
public:
    MyHashMap() {
        hash = vector<int>(1000005, -1);
    }
    
    void put(int key, int value) {
        hash[key] = value;
    }
    
    int get(int key) {
        return hash[key];
    }
    
    void remove(int key) {
        hash[key] = -1;
    }
private:
    vector<int> hash;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

// STL double-directed list
class MyHashMap {
public:
    MyHashMap() {
        nums = vector<list<pair<int, int>>>(N);
    }
    
    int getHashKey(int key) {
        return key % N;
    }

    list<pair<int, int>>::iterator find(int key) {
        auto hashKey = getHashKey(key);
        auto& numList = nums[hashKey];
        for (auto iter = numList.begin(); iter != numList.end(); iter++) {
            if (iter->first == key) {
                return iter;
            }
        }
        return numList.end();
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto hashKey = getHashKey(key);
        auto iter = find(key);
        if (iter != nums[hashKey].end()) {
            iter->second = value;
            return;
        }

        nums[hashKey].push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto hashKey = getHashKey(key);
        auto iter = find(key);
        if (iter != nums[hashKey].end())
            return iter->second;

        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto hashKey = getHashKey(key);
        auto iter = find(key);
        if (iter != nums[hashKey].end())
            nums[hashKey].erase(iter);
    }

private:
    static const int N = 1009;
    vector<list<pair<int, int> > > nums;
};