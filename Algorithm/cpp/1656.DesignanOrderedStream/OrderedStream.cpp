class OrderedStream {
public:
    int capacity_, next_ = 1;
    vector<string> stream_;
    OrderedStream(int n): capacity_(n), stream_(n + 1, "") {
    }
    
    vector<string> insert(int idKey, string value) {
        stream_[idKey] = value;
        vector<string> ans;
        while(next_ <= capacity_ && stream_[next_] != ""){
            ans.push_back(stream_[next_]);
            ++next_;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */