struct Segtree {
    int n;
    vector<int> tree, lz;
    Segtree(int n) : n(n), tree(4 * n + 5), lz(4 * n + 5) {}
    void build(int v, int s, int e, vector<int>& A) {
        if (s == e) {
            tree[v] = A[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, A);
        build(v << 1 | 1, mid + 1, e, A);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    void push(int v) {
        if (!lz[v]) return;
        lz[v] = 0;
        lz[v << 1] = lz[v << 1 | 1] = 1;
        tree[v << 1] = tree[v << 1 | 1] = tree[v];
    }
    void upd(int v, int s, int e, int l, int r, int val) {
        if (s == l && e == r) {
            tree[v] = val;
            lz[v] = 1;
            return;
        }
        push(v);
        int mid = (s + e) >> 1;
        if (r <= mid) upd(v << 1, s, mid, l, r, val);
        else if (l >= mid + 1) upd(v << 1 | 1, mid + 1, e, l, r, val);
        else {
            upd(v << 1, s, mid, l, mid, val);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, val);
        }
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    void upd(int l, int r, int val) {
        if (l > r) return;
        upd(1, 0, n - 1, l, r, val);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        push(v);
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        else {
            return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
        }
    }
    int get(int l, int r) {
        if (l > r) return -1;
        return get(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> ret;

        const int INF = 1e9;
        vector<int> bat;
        set<int> se;
        int qlen = (int)queries.size();

        se.insert(0);
        se.insert(INF);
        bat.push_back(0);
        bat.push_back(INF);
        for (auto q : queries) {
            if (q[0] == 1) {
                se.insert(q[1]);
                bat.push_back(q[1]);
            }
        }
        sort(bat.begin(), bat.end());
        int sz = bat.size();
        vector<int> itv(sz - 1);
        for (int i = 1; i < sz; i++) itv[i - 1] = bat[i] - bat[i - 1];

        Segtree sgt(sz - 1);
        sgt.build(1, 0, sz - 2, itv);

        for (int i = qlen - 1; i >= 0; i--) {
            if (queries[i][0] == 1) {
                auto ptr = se.find(queries[i][1]);
                int y = *(++ptr);
                --ptr;
                int x = *(--ptr);
                int i1 = lower_bound(bat.begin(), bat.end(), queries[i][1]) - bat.begin();
                int i2 = lower_bound(bat.begin(), bat.end(), x) - bat.begin();
                int i3 = lower_bound(bat.begin(), bat.end(), y) - bat.begin();
                int ki = sgt.get(i1 - 1, i1 - 1);
                int ka = sgt.get(i1, i1);
                sgt.upd(i2, i3 - 1, ki + ka);
                se.erase(queries[i][1]);
            } else {
                int x = queries[i][1], sz = queries[i][2];
                auto ptr = se.upper_bound(x);
                --ptr;
                int i1 = lower_bound(bat.begin(), bat.end(), *ptr) - bat.begin();
                int mx = sgt.get(0, i1 - 1);
                mx = max(mx, x - *ptr);
                ret.push_back((mx >= sz));
            }
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};