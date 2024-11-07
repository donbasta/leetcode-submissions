class Segtree {
  public:
    vector<pair<int, int>> tree;
    Segtree(int n) {
        tree.resize(4 * n + 5);
    }
    void build(int v, int s, int e, const vector<int>& a) {
        if (s == e) {
            tree[v] = make_pair(a[s], s);
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, a);
        build(v << 1 | 1, mid + 1, e, a);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    pair<int, int> get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = make_pair(val, idx);
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid) upd(v << 1, s, mid, idx, val);
        else if (idx >= mid + 1) upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> ve;
        int n = profits.size();
        for (int i = 0; i < n; i++) {
            ve.emplace_back(capital[i], profits[i]);
        }
        sort(ve.begin(), ve.end());

        Segtree sgt(n);
        vector<int> pr;
        for (auto e : ve) pr.emplace_back(e.second);
        sgt.build(1, 0, n - 1, pr);

        const int INF = 2e9;

        for (int i = 0; i < min(k, n); i++) {
            int bruh = lower_bound(ve.begin(), ve.end(), make_pair(w + 1, -INF)) - ve.begin();
            if (bruh == 0) {
                return w;
            }
            pair<int, int> mx = sgt.get(1, 0, n - 1, 0, bruh - 1);
            w += mx.first;
            sgt.upd(1, 0, n - 1, mx.second, 0);
        }
        return w;
    }
};