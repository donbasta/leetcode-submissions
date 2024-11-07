class NumberContainers {
private:
    unordered_map<int, set<int>> ump;
    unordered_map<int, int> cur;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (cur.count(index)) {
            int x = cur[index];
            ump[x].erase(index);
            if (ump[x].empty()) ump.erase(x);
        }
        cur[index] = number;
        ump[number].insert(index);
    }
    
    int find(int number) {
        if (!ump.count(number)) return -1;
        return *ump[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */