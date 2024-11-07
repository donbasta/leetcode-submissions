class LFUCache {
public:
    int timer = 0;
    unordered_map<int, int> kVal, kTim, kUse;
    set<pair<pair<int, int>, int>> se;
    int capacity;

    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (kVal.find(key) == kVal.end()) {
            return -1;
        }
        se.erase(se.find(make_pair(make_pair(kUse[key], kTim[key]), key)));
        kTim[key] = timer++;
        kUse[key]++;
        se.emplace(make_pair(kUse[key], kTim[key]), key);
        return kVal[key];
    }
    
    void put(int key, int value) {
        if (this->capacity == 0) return;
        if (kVal.find(key) != kVal.end()) {
            se.erase(se.find(make_pair(make_pair(kUse[key], kTim[key]), key)));
            kUse[key]++;
            kTim[key] = timer++;
            kVal[key] = value;
            se.emplace(make_pair(kUse[key], kTim[key]), key);
            return;
        }
        if (kVal.size() < this->capacity) {
            kUse[key] = 1;
            kTim[key] = timer++;
            kVal[key] = value;
            se.emplace(make_pair(kUse[key], kTim[key]), key);
            return;
        }
        auto buang = se.begin();
        kUse.erase(buang->second);
        kTim.erase(buang->second);
        kVal.erase(buang->second);
        se.erase(buang);
        kUse[key] = 1;
        kTim[key] = timer++;
        kVal[key] = value;
        se.emplace(make_pair(kUse[key], kTim[key]), key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */