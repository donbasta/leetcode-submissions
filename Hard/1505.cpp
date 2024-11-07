struct Segtree {
    int n;
    vector<int> lz;
    Segtree(int n) : n(n), lz(4 * n + 5) {}
    void push(int v) {
        lz[v << 1] += lz[v];
        lz[v << 1 | 1] += lz[v];
        lz[v] = 0;
    }
    void upd(int v, int s, int e, int l, int r, int add) {
        if (s == l && e == r) {
            lz[v] += add;
            return;
        }
        push(v);
        int mid = (s + e) >> 1;
        if (r <= mid) upd(v << 1, s, mid, l, r, add);
        else if (l >= mid + 1) upd(v << 1 | 1, mid + 1, e, l, r, add);
        else {
            upd(v << 1, s, mid, l, mid, add);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, add);
        }
    }
    int get(int v, int s, int e, int idx) {
        if (s == e) return lz[v];
        push(v);
        int mid = (s + e) >> 1;
        if (idx <= mid) return get(v << 1, s, mid, idx);
        return get(v << 1 | 1, mid + 1, e, idx);
    }
    void upd(int l, int r, int add) {
        if (l > r) return;
        upd(1, 0, n - 1, l, r, add);
    }
    int get(int idx) {
        return get(1, 0, n - 1, idx);
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.length();
        string ret;
        vector<vector<int>> pos(10);
        for (int i = 0; i < n; i++) {
            pos[num[i] - '0'].push_back(i);
        }
        vector<Segtree> sgt;
        for (int i = 0; i < 10; i++) {
            sgt.push_back(Segtree(pos[i].size()));
        }
        for (int i = 0; i < n; i++) {
            vector<int> L(10, -1);
            int cur = -1;
            for (int j = 0; j < 10; j++) {
                if (pos[j].empty()) continue;
                int l = 0, r = (int)pos[j].size() - 1, piv = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (pos[j][mid] + sgt[j].get(mid) >= i) {
                        piv = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                L[j] = piv;
                if (piv != -1 && pos[j][piv] + sgt[j].get(piv) == i) {
                    cur = j;
                }
            }
            assert (cur != -1);
            int add = cur;
            for (int j = 0; j < cur; j++) {
                if (L[j] == -1) continue;
                int piv = L[j];
                int swap = pos[j][piv] + sgt[j].get(piv);
                if (swap - i > k) continue;
                k -= (swap - i);
                add = j;
                for (int dig = 0; dig < 10; dig++) {
                    int l = 0, r = (int)pos[dig].size() - 1, piv = -1;
                    while (l <= r) {
                        int mid = (l + r) >> 1;
                        if (pos[dig][mid] + sgt[dig].get(mid) < swap) {
                            piv = mid;
                            l = mid + 1;
                        } else {
                            r = mid - 1;
                        }
                    }
                    sgt[dig].upd(0, piv, 1);
                }
                sgt[j].upd(piv, piv, i - swap);
                break;
            }
            ret.push_back((char) (add + '0'));
        }
        return ret;
    }
};
