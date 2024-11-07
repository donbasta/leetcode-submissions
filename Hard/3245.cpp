struct BIT {
    vector<int> bit;
    int n;
    BIT(int n) : n(n), bit(n + 1) {}
    void upd(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
    int get(int idx) {
        int ret = 0;
        while (idx) {
            ret += bit[idx];
            idx -= idx & -idx;
        }
        return ret;
    }
    int get(int a, int b) {
        return get(b) - get(a - 1);
    }
};

class Solution {
public:
    vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<int> ve;
        for (int i = 0; i < 2 * n - 1; i++) {
            if (i % 2 == 0) ve.emplace_back(colors[i % n]);
            else ve.emplace_back(1 - colors[i % n]);
        }

        BIT t1(2 * n - 1), c1(2 * n - 1), t2(n - 1), c2(n - 1);
        set<pair<int, int>> s1, s2;

        auto add_itv = [&](set<pair<int, int>>& S, BIT& C, BIT& T, int l, int r) {
            if (l > r) return;
            int len = r - l + 1;
            S.emplace(l, r);
            C.upd(len, 1);
            T.upd(len, len);
        };

        auto rem_itv = [&](set<pair<int, int>>& S, BIT& C, BIT& T, int l, int r) {
            if (l > r) return;
            int len = r - l + 1;
            S.erase(make_pair(l, r));
            C.upd(len, -1);
            T.upd(len, -len);
        };

        auto build = [&](int s, int e, set<pair<int, int>>& S, BIT& C, BIT& T) {
            int st = s;
            for (int i = s + 1; i <= e; i++) {
                if (ve[i] == ve[st]) continue;
                else {
                    add_itv(S, C, T, st, i - 1);
                    st = i;
                }
            }
            add_itv(S, C, T, st, e);
        };

        build(0, 2 * n - 2, s1, c1, t1);
        build(n, 2 * n - 2, s2, c2, t2);

        auto upd = [&](set<pair<int, int>>& S, int idx, BIT& C, BIT& T) {
            auto itr = S.lower_bound(make_pair(idx + 1, -1));
            assert (itr != S.begin());
            --itr;
            int L = itr->first, R = itr->second;
            if (idx == L && idx == R) {
                int le = idx, ri = idx;
                vector<pair<int, int>> tmp;
                tmp.emplace_back(L, R);
                if (itr != S.begin()) {
                    auto itr2 = itr;
                    --itr2;
                    le = itr2->first;
                    tmp.emplace_back(itr2->first, itr2->second);
                }
                if ((++itr) != S.end()) {
                    assert (itr != S.end());
                    ri = itr->second;
                    tmp.emplace_back(itr->first, itr->second);
                }
                for (auto rem : tmp) rem_itv(S, C, T, rem.first, rem.second);
                add_itv(S, C, T, le, ri);
            } else if (idx == L) { 
                int le = idx;
                vector<pair<int, int>> tmp;
                tmp.emplace_back(L, R);
                if (itr != S.begin()) {
                    auto itr2 = itr;
                    --itr2;
                    le = itr2->first;
                    tmp.emplace_back(itr2->first, itr2->second);
                }
                for (auto rem : tmp) rem_itv(S, C, T, rem.first, rem.second);
                add_itv(S, C, T, le, idx);
                add_itv(S, C, T, idx + 1, R);
            } else if (idx == R) {
                int ri = idx;
                vector<pair<int, int>> tmp;
                tmp.emplace_back(L, R);
                if ((++itr) != S.end()) {
                    ri = itr->second;
                    tmp.emplace_back(itr->first, itr->second);
                }
                for (auto rem : tmp) rem_itv(S, C, T, rem.first, rem.second);
                add_itv(S, C, T, L, idx - 1);
                add_itv(S, C, T, idx, ri);
            } else {
                rem_itv(S, C, T, L, R);
                add_itv(S, C, T, L, idx - 1);
                add_itv(S, C, T, idx, idx);
                add_itv(S, C, T, idx + 1, R);
            }
        };

        vector<int> ret;

        int X = 0;
        for (auto q : queries) {
            if (q[0] == 1) {
                int A = t1.get(q[1], 2 * n - 1) - (q[1] - 1) * c1.get(q[1], 2 * n - 1);
                int B = t2.get(q[1], n - 1) - (q[1] - 1) * c2.get(q[1], n - 1);
                ret.push_back(A - B);
            } else {
                int idx = q[1], col = q[2];
                if ((col + idx) % 2 != ve[idx]) {
                    ve[idx] = (col + idx) % 2;
                    upd(s1, idx, c1, t1);
                    if (idx != n - 1) {
                        ve[idx + n] = (col + idx + n) % 2;
                        upd(s1, idx + n, c1, t1);
                        upd(s2, idx + n, c2, t2);
                    }
                }
            }
        }
        return ret;
    }
};