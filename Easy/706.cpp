class MyHashMap {
public:
    int bruh[1000001];

    MyHashMap() {
        memset(bruh, -1, sizeof(bruh));
    }
    
    void put(int key, int value) {
        bruh[key] = value;
    }
    
    int get(int key) {
        return bruh[key];
    }
    
    void remove(int key) {
        bruh[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */