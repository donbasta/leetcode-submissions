struct DS {
    set<pair<int, pair<int, int>>> se; //length, interval
    set<pair<int, int>> itv; //interval
    DS() {}
    void add_range(int l, int r) {
        se.emplace(r - l + 1, make_pair(l, r));
        itv.emplace(l, r);
    }
    void remove_range(int l, int r) {
        assert(itv.count(make_pair(l, r)));
        se.erase(make_pair(r - l + 1, make_pair(l, r)));
        itv.erase(make_pair(l, r));
    }
    void erase(int idx) {
        auto p1 = itv.lower_bound(make_pair(idx + 1, -1));
        assert (p1 != itv.begin());
        --p1;
        assert (p1->second >= idx);
        int L = p1->first, R = p1->second;
        remove_range(L, R);
        if (L <= idx - 1) {
            add_range(L, idx - 1);
        }
        if (idx + 1 <= R) {
            add_range(idx + 1, R);
        }
    }
    void insert(int idx) {
        auto p1 = itv.lower_bound(make_pair(idx + 1, -1));
        int L, R;
        if (p1 != itv.end() && p1->first == idx + 1) {
            L = p1->first, R = p1->second;
            remove_range(L, R);
            add_range(idx, R);
        } else {
            add_range(idx, idx);
        }
        auto p2 = itv.lower_bound(make_pair(idx, -1));
        assert (p2 != itv.end());
        int right = p2->second;
        if (p2 != itv.begin() && (--p2)->second == idx - 1) {
            L = p2->first, R = p2->second;
            remove_range(L, R);
            remove_range(idx, right);
            add_range(L, right);
        }
    }
    int get() {
        if (se.empty()) return 0;
        return se.rbegin()->first;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        char cur = s[0];
        int fi = 0;
        vector<DS> ds(26);
        for (int i = 1; i < n; i++) {
            if (cur != s[i]) {
                ds[cur - 'a'].add_range(fi, i - 1);
                fi = i;
                cur = s[i];
            }
        }
        ds[cur - 'a'].add_range(fi, n - 1);

        int k = queryCharacters.length();
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            int old = s[queryIndices[i]] - 'a';
            int nw = queryCharacters[i] - 'a';
            ds[old].erase(queryIndices[i]);
            ds[nw].insert(queryIndices[i]);
            int mx = -1;
            for (int j = 0; j < 26; j++) {
                mx = max(mx, ds[j].get());
            }
            ret.push_back(mx);
            s[queryIndices[i]] = queryCharacters[i];
        }

        return ret;
    }
};