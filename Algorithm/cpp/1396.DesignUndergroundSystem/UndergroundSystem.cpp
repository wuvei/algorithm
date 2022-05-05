class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ckin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string inStation = ckin[id].first;
        int inTime = ckin[id].second;
        if (!data.count(inStation) || !data[inStation].count(stationName))
            data[inStation][stationName] = {1, t - inTime};
        else {
            ++data[inStation][stationName].first;
            data[inStation][stationName].second += t - inTime;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return 1.0 * data[startStation][endStation].second / data[startStation][endStation].first;
    }
private:
    unordered_map<int, pair<string, int> > ckin;
    unordered_map<string, unordered_map<string, pair<int, int> > > data;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */