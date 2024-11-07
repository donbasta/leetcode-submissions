class CountIntervals {
public:
    set<pair<int, int>> intervals;
    int cnt = 0;

    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        if (intervals.empty()) {
            intervals.emplace(left, right);
            cnt = right - left + 1;
            return;
        }
        auto bruh = intervals.lower_bound(make_pair(right + 1, -1));
        if (bruh == intervals.begin()) {
            intervals.emplace(left, right);
            cnt += right - left + 1;
            return;
        }
        int L = left, R = right;
        int intersect = 0;
        vector<pair<int, int>> toErase;
        for (auto it = --bruh; ; --it) {
            if (it->second < left) {
                break;
            }
            int l = it->first, r = it->second;
            toErase.emplace_back(l, r);
            L = min(L, l), R = max(R, r);
            int overlap = min(r, right) - max(l, left) + 1;
            intersect += overlap;
            if (it == intervals.begin()) break;
        }
        for (auto e : toErase) intervals.erase(intervals.find(e));
        intervals.emplace(L, R);
        cnt += (right - left + 1) - intersect;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */