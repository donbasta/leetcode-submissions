class MyHashSet {
public:
    bool ada[1000001];
    MyHashSet() {
        memset(ada, 0, sizeof(ada));
    }
    
    void add(int key) {
        ada[key] = true;
    }
    
    void remove(int key) {
        ada[key] = false;
    }
    
    bool contains(int key) {
        return ada[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */