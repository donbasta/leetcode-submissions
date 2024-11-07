class LRUCache {
public:
    unordered_map<int, int> lastUsed;
    unordered_map<int, int> kV;
    deque<pair<int, int>> de;
    int t = 0;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;        
    }

    int get(int key) {
        if (kV.find(key) == kV.end()) return -1;
        lastUsed[key] = t++;
        de.push_front(make_pair(key, lastUsed[key]));
        return kV[key];        
    } 
    
    void put(int key, int value) {
        if (kV.find(key) == kV.end() && kV.size() >= cap) {
            while (true) {
                pair<int, int> hehe = de.back();
                if (lastUsed.find(hehe.first) == lastUsed.end() || hehe.second != lastUsed[hehe.first]) {
                    de.pop_back();
                } else if (hehe.second == lastUsed[hehe.first]) {
                    de.pop_back();
                    lastUsed.erase(hehe.first);
                    kV.erase(hehe.first);
                    break;
                }
            }
        }
        kV[key] = value;
        lastUsed[key] = t++;
        de.push_front(make_pair(key, lastUsed[key]));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */