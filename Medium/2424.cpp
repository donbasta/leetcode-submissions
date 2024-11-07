class LUPrefix {
public:
    set<pair<int, int>> intervals;
    LUPrefix(int n) {
        
    }
    
    void upload(int video) {
        auto X = intervals.lower_bound(make_pair(video + 1, -1));
        if (X == intervals.begin()) {
            if (X->first == video + 1) {
                int r = X->second;
                intervals.erase(X);
                intervals.insert(make_pair(video, r));
            } else {
                intervals.insert(make_pair(video, video));
            }
        } else {
            auto Y = X;
            --Y;
            int l = Y->first, r = X->second;
            if (X->first == video + 1 && Y->second == video - 1) {
                intervals.erase(X), intervals.erase(Y);
                intervals.insert(make_pair(l, r));
            } else if (X->first == video + 1) {
                intervals.erase(X);
                intervals.insert(make_pair(video, r));
            } else if (Y->second == video - 1) {
                intervals.erase(Y);
                intervals.insert(make_pair(l, video));
            } else {
                intervals.insert(make_pair(video, video));
            }
        }
    }
    
    int longest() {
        if (intervals.empty()) return 0;
        if (intervals.begin()->first != 1) return 0;
        return intervals.begin()->second;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */