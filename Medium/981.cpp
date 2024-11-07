class TimeMap {
public:
    unordered_map<string, set<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto itr = mp[key].lower_bound(make_pair(timestamp + 1, ""));
        if (itr == mp[key].begin()) return "";
        --itr;
        return itr->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */