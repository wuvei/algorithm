static int n;
class ExamRoom {
public:
    struct comp{
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
            int x1 = p1.first == -1 || p1.second==n ? p1.second-p1.first-1 : (p1.second-p1.first) >> 1;
            int x2 = p2.first == -1 || p2.second==n ? p2.second-p2.first-1 : (p2.second-p2.first) >> 1;
            return (x1 == x2 && p1.first < p2.first) || x1 > x2;
        }
    };
    set<pair<int,int>, comp> s;
    ExamRoom(int N) {
        n = N;
        s.insert({-1, n});
    }
    int seat() {
        auto it = s.begin();
        auto [b,e] = *it;
        int chair;
        s.erase(it);
        if (b == -1) {
            chair = 0;
            s.insert({0, e});
        }
        else if (e == n) {
            chair = n - 1;
            s.insert({b, n - 1});
        }
        else{
            chair = b + ((e - b) >> 1);
            s.insert({b, chair});
            s.insert({chair, e});
        }
        return chair;
    }
    void leave(int p) {
        if (p == 0){
            auto it = find_if(s.begin(), s.end(), [](const pair<int,int>& pp){
                return pp.first == 0;
            });
            auto [b,e] = *it;
            s.erase(it);
            s.insert({-1, e});
        }
        else if(p == n - 1){
            auto it = find_if(s.begin(), s.end(), [&](const pair<int,int>& pp){
                return pp.second == n-1;
            });
            auto [b,e] = *it;
            s.erase(it);
            s.insert({b, n});
        }
        else{
            auto it = find_if(s.begin(), s.end(), [&](const pair<int,int>& pp){
                return pp.first == p;
            });
            auto [_, e] = *it;
            s.erase(it);
            it = find_if(s.begin(), s.end(),[ &](const pair<int,int>& pp){
                return pp.second == p;
            });
            auto [b, __] = *it;
            s.erase(it);
            s.insert({b, e});
        }
    }
};