class AllOne {
public:
    unordered_set<string> S[50001];
    unordered_map<string, int> cnt;
    int mx, mn, sz;

    AllOne() {
        mx = -1, mn = -1, sz = 0;
    }
    
    void inc(string key) {
        if (sz == 0) {
            mx = mn = 1;
            sz = 1;
            cnt[key] = 1;
            S[1].insert(key);
            return;
        }
        if (cnt.count(key)) {
            S[cnt[key]].erase(key);
            if (mn == cnt[key] && S[cnt[key]].empty()) {
                mn++;
            }
        }
        sz++;
        cnt[key]++;
        S[cnt[key]].insert(key);
        if (cnt[key] > mx) {
            mx++;
        }
        if (cnt[key] < mn) {
            assert (cnt[key] == 1);
            mn = cnt[key];
        }
    }
    
    void dec(string key) {
        S[cnt[key]].erase(key);
        if (cnt[key] == mx && S[cnt[key]].empty()) {
            mx--;
        }
        sz--;
        cnt[key]--;
        if (cnt[key] > 0) {
            S[cnt[key]].insert(key);
            if (cnt[key] < mn) {
                mn--;
            }
        } else {
            assert (mn == 1);
            cnt.erase(key);
            if (sz != 0) {
                while (S[mn].empty()) {
                    mn++;
                }
            }
        }
        if (sz == 0) {
            mn = mx = -1;
        }
    }

    string getMaxKey() {
        if (sz == 0) return "";
        return *S[mx].begin();
    }
    
    string getMinKey() {
        if (sz == 0) return "";
        return *S[mn].begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */