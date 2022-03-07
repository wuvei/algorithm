class RandomizedSet {
private:
    unordered_map<int, int> hash;    //哈希表储存元素值和对应下标，为了remove时实现O（1）
    vector<int> dyArray;        //vector可以作为动态数组，实现getRandom和insert的常数时间操作

public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash.find(val) != hash.end()) return false;
        hash[val] = dyArray.size();
        dyArray.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hash.find(val) == hash.end()) return false;        
        int lastElem = dyArray.back();
        hash[lastElem] = hash[val];
        dyArray[hash[val]] = lastElem;
        dyArray.pop_back();
        hash.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return dyArray[rand() % dyArray.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */