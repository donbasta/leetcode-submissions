class FrequencyTracker {
public:
    map<int, set<int>> m1;
    map<int, int> m2;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if (m2.count(number)) m1[m2[number]].erase(number);
        m2[number]++;
        m1[m2[number]].insert(number);
    }
    
    void deleteOne(int number) {
        if (!m2.count(number)) return;
        m1[m2[number]].erase(number);
        m2[number]--;
        if (m2[number] == 0) m2.erase(number);
        else m1[m2[number]].insert(number);
    }
    
    bool hasFrequency(int frequency) {
        return (m1.count(frequency) && m1[frequency].size() > 0);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */