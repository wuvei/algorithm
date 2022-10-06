class TimeMap {
public:
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string> > &v = m[key];
        if (!v.size() || timestamp < v.begin()->first) {
            return "";
        }
        if (timestamp >= v.back().first) {
            return v.back().second;
        }
        pair<int, string> p = {timestamp, ""};
        auto it = std::upper_bound(v.begin(), v.end(), p, [](const pair<int, string> &a, const pair<int, string> &b) {
            return a.first < b.first;
        });
        return (*prev(it)).second;
    }
private:
    unordered_map<string, vector<pair<int, string>> > m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */