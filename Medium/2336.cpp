class SmallestInfiniteSet {
public:
    set<int> se;

    SmallestInfiniteSet() {
        se.insert(1);
    }
    
    int popSmallest() {
        if (se.size() == 1) {
            int ret = *se.begin();
            se.clear();
            se.insert(ret + 1);
            return ret;
        }
        int ret = *se.begin();
        se.erase(se.begin());
        return ret;
    }
    
    void addBack(int num) {
        int bat = *se.rbegin();
        if (num < bat) {
            se.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */