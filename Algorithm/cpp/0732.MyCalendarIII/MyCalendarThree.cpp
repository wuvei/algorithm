// DIFFERECE ARRAY
class MyCalendarThree {
    int maxCnt = 0;
    map<int, int> mp;
public:    
    int book(int start, int end) {
        ++mp[start];
        --mp[end];
        int cnt = 0;
        for (auto &[_, freq] : mp) 
        {
            cnt += freq;
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;
    }
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

