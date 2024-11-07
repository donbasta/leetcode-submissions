class SummaryRanges {
public:
    set<pair<int, int>> intervals;

    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if (intervals.empty()) {
            intervals.insert(make_pair(value, value));
            return;
        }
        // value already inside an interval or not? --> 
        auto atas = intervals.lower_bound(make_pair(value, -1));
        if (atas == intervals.end()) {
            --atas;
            if (atas->second == value - 1) {
                int hehe = atas->first;
                intervals.erase(atas);
                intervals.insert(make_pair(hehe, value));
            } else if (atas->second < value - 1) {
                intervals.insert(make_pair(value, value));
            }
        } else if (atas->first == value) {
            return;
        } else if (atas->first > value + 1) {
            //cek nempel bawah ga
            if (atas == intervals.begin()) {
                intervals.insert(make_pair(value, value));
            } else {
                --atas;
                if (atas->second == value - 1) {
                    int hehe = atas->first;
                    intervals.erase(atas);
                    intervals.insert(make_pair(hehe, value));
                } else if (atas->second < value - 1) {
                    intervals.insert(make_pair(value, value));
                }
            }
        } else if (atas->first == value + 1) {
            //cek nempel bawah ga
            int hihi = atas->second;
            if (atas == intervals.begin()) {
                intervals.erase(atas);
                intervals.insert(make_pair(value, hihi));
            } else {
                auto catas = atas;
                --catas;
                if (catas->second == value - 1) {
                    int hehe = catas->first;
                    intervals.erase(atas);
                    intervals.erase(catas);
                    intervals.insert(make_pair(hehe, hihi));
                } else {
                    intervals.erase(atas);
                    intervals.insert(make_pair(value, hihi));
                }
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto e : intervals) {
            ans.push_back({e.first, e.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */