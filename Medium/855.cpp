class ExamRoom {
public:
    set<int> occ;
    map<int, set<pair<int, int>>> itv;
    int n;
    ExamRoom(int n) : n(n) {
        
    }
    
    int seat() {
        if (occ.empty()) {
            occ.insert(0);
            return 0;
        }
        if (occ.size() == 1) {
            int lmao = *occ.begin();
            int pick;
            if (lmao >= n - 1 - lmao) {
                occ.insert(0);
                itv[lmao].emplace(0, lmao);
                pick = 0;
            } else {
                occ.insert(n - 1);
                itv[n - 1 - lmao].emplace(lmao, n - 1);
                pick = n - 1;
            }
            return pick;
        }
        int largest_dif = itv.rbegin()->first / 2;
        // cout << largest_dif << '\n';
        // cout << occ.size() << '\n';
        // cout << itv.rbegin()->first << '\n';
        // cout << "--\n";
        int fi = *occ.begin(), la = *occ.rbegin();
        int pick = -1;
        if (!occ.count(0) && (fi >= largest_dif) && (fi >= n - 1 - la)) {
            pick = 0;
            occ.insert(0);
            itv[fi].emplace(0, fi);
        } else if (!occ.count(n - 1) && (n - 1 - la > largest_dif) && (n - 1 - la > fi)) {
            pick = n - 1;
            occ.insert(n - 1);
            itv[n - 1 - la].emplace(la, n - 1);
        } else {
            pick = n;
            if (itv.count(2 * largest_dif)) {
                pick = min(pick, itv[2 * largest_dif].begin()->first + largest_dif);
            } 
            if (itv.count(2 * largest_dif + 1)) {
                pick = min(pick, itv[2 * largest_dif + 1].begin()->first + largest_dif);
            }
            auto ptr = occ.lower_bound(pick);
            auto ptr2 = ptr;
            --ptr2;
            itv[*ptr - *ptr2].erase(make_pair(*ptr2, *ptr));
            if (itv[*ptr - *ptr2].empty()) itv.erase(*ptr - *ptr2);
            itv[pick - *ptr2].emplace(*ptr2, pick);
            itv[*ptr - pick].emplace(pick, *ptr);
            occ.insert(pick);
        }
        return pick;
    }

    void leave(int p) {
        auto x = occ.lower_bound(p);
        int u = -1, v = -1;
        if (x != occ.begin()) {
            auto y = x;
            --y;
            u = *y;
            itv[p - u].erase(make_pair(u, p));
            if (itv[p - u].empty()) itv.erase(p - u);
        }
        if ((++x) != occ.end()) {
            v = *x;
            itv[v - p].erase(make_pair(p, v));
            if (itv[v - p].empty()) itv.erase(v - p);
        }
        if (u != -1 && v != -1) {
            itv[v - u].emplace(u, v);
        }
        occ.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */