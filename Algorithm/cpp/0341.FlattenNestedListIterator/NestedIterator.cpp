class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i)
            st.push(nestedList[i]);
    }

    int next() {
        NestedInteger cur = st.top(); st.pop();
        return cur.getInteger();
    }

    bool hasNext() {
        while (!st.empty()) {
            NestedInteger cur = st.top();
            if (cur.isInteger()) return true;
            st.pop();
            for (int i = cur.getList().size() - 1; i >= 0; --i)
                st.push(cur.getList()[i]);
        }
        return false;
    }
private:
    stack<NestedInteger> st;
};

class NestedIterator {
public:
    deque<int> q;
    NestedIterator(vector<NestedInteger> &nestedList) {
        std::function<void(vector<NestedInteger>)> dfs = [&](vector<NestedInteger> nestedList){
            for(const auto& x : nestedList){
                if(x.isInteger()) q.push_back(x.getInteger());
                else dfs(x.getList());
            }
        };
        dfs(nestedList);
    }
    int next() {
        int ret = q.front(); q.pop_front();
        return ret;
    }
    
    bool hasNext() {
        return q.size();
    }
};