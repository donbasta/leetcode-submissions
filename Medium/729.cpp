class MyCalendar {
public:
    set<pair<int, int>> events;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto ptr = events.lower_bound(make_pair(end, -1));
        if (ptr == events.begin()) {
            events.emplace(start, end);
            return true;
        }
        --ptr;
        if (ptr->second > start) return false;
        events.emplace(start, end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */