class StockPrice {
public:
    int latest = 0;
    unordered_map<int, int> mp;
    set<pair<int, int>> se;
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        if (mp.find(timestamp) != mp.end()) se.erase(se.find(make_pair(mp[timestamp], timestamp)));
        mp[timestamp] = price;
        latest = max(latest, timestamp);
        se.emplace(mp[timestamp], timestamp);
    }
    
    int current() {
        return mp[latest];
    }
    
    int maximum() {
        return se.rbegin()->first;
    }
    
    int minimum() {
        return se.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */