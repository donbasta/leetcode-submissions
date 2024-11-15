class UndergroundSystem {
private:
    map<pair<string, string>, int> tot;
    map<pair<string, string>, int> cnt;
    unordered_map<int, string> from;
    unordered_map<int, int> enter_time; 
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        enter_time[id] = t;
        from[id] = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        tot[make_pair(from[id], stationName)] += (t - enter_time[id]);
        cnt[make_pair(from[id], stationName)]++;
        from.erase(id);
        enter_time.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        pair<string, string> key = make_pair(startStation, endStation);
        assert (tot.count(key));
        return (double)tot[key] / cnt[key];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */