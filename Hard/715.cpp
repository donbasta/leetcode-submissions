class RangeModule {
public:
    set<pair<int, int>> intervals;

    RangeModule() {
        
    }

    void cetakInterval() {
        cout << "--------\n";
        for (auto e : intervals) {
            cout << "(" << e.first << "," << e.second << ") -- ";
        }
        cout << "\n--------\n\n";
    }
     
    void addRange(int left, int right) {
        if (intervals.empty()) {
            intervals.emplace(left, right);
            return;
        }
        auto le = intervals.lower_bound(make_pair(right + 1, -1));
        if (le == intervals.begin()) {
            intervals.emplace(left, right);
            return;
        }
        vector<pair<int, int>> toErase;
        int newLeft = left, newRight = right;
        for (auto it = --le; ; --it) {
            int L = it->first, R = it->second;
            if (R < left) break;
            toErase.emplace_back(L, R);
            newRight = max(newRight, R);
            newLeft = min(newLeft, L);
            if (it == intervals.begin()) break;
        }
        for (auto e : toErase) {
            intervals.erase(intervals.find(e));
        }
        intervals.emplace(newLeft, newRight);

        // cout << "addRange " << left << ' ' << right << ' ';
        // cetakInterval();
    }
    
    bool queryRange(int left, int right) {
        if (intervals.empty()) return false;
        auto cari = intervals.lower_bound(make_pair(right + 1, -1));
        if (cari == intervals.begin()) {
            return false;
        }
        --cari;
        return ((cari->first <= left) && (cari->second >= right));
    }
    
    void removeRange(int left, int right) {
        if (intervals.empty()) return;
        auto cari = intervals.lower_bound(make_pair(right + 1, -1));
        if (cari == intervals.begin()) return;
        vector<pair<int, int>> toErase, toInsert;
        for (auto it = --cari; ; --it) {
            int L = it->first, R = it->second;
            if (R < left) break;
            toErase.emplace_back(L, R);
            if (L < left) {
                toInsert.emplace_back(L, left);
            }
            if (R > right) {
                toInsert.emplace_back(right, R);
            }
            if (it == intervals.begin()) break;
        }
        for (auto e : toErase) {
            intervals.erase(intervals.find(e));
        }
        for (auto e : toInsert) {
            intervals.insert(e);
        }

        // cout << "removeRange " << left << ' ' << right << ' ';
        // cetakInterval();
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */