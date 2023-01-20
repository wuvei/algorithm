class MKAverage {
public:
    int m, k, c = 0;
    vector<int> a;
    map<int,int> mm;
    MKAverage(int _m, int _k): m(_m), k(_k), a(100001) {
    }
    
    void addElement(int num) {
        a[c] = num;
        ++mm[num];
        if(c >= m) { // deleting the left out element
            --mm[a[c - m]];
            if(!mm[a[c - m]])
                mm.erase(mm.find(a[c - m]));
        }
        ++c;
    }
    
    int calculateMKAverage() {
        if(c < m)
            return -1;
        int d = m - 2 * k;
        int s = 0, ss = 0;
        for(auto t: mm) {
		    //adding for witing range [k,d+k] 
            if(ss < k && ss + t.second > k + d)
                s += (t.second - (k - ss) - (ss + t.second - (k + d))) * t.first;
            else if(ss >= k && ss + t.second > k + d)
                s += (t.second - (ss + t.second - (k + d)))*t.first;
            else if(ss >= k && ss + t.second <= k + d)
                s += t.second * t.first;
            else if(ss < k && ss + t.second >= k)
                s += (t.second - (k - ss)) * t.first;
            ss += t.second;
            if(ss >= k+d)
                break;
        }
        return s / d;
    }
};