struct Segtree {
    vector<int> tree;
    int n;
    Segtree(int n) : n(n), tree(4 * n + 5) {}
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid) upd(v << 1, s, mid, idx, val);
        else upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
    }
    int query(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return query(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return query(v << 1 | 1, mid + 1, e, l, r);
        return min(query(v << 1, s, mid, l, mid), query(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    void upd(int idx, int val) {
        upd(1, 0, n - 1, idx, val);
    }
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        Segtree sgt(n + k);
        vector<int> cnt(k);
        for (int i = 0; i < n; i++) {
            int start = arrival[i];
            int end = start + load[i];
            int l = i, r = (i + k - 1), piv = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sgt.query(i, mid) <= start) {
                    piv = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (piv != -1) {
                cnt[piv % k]++;
                sgt.upd(piv, end);
            }
            sgt.upd(i + k, sgt.query(i, i));
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) ans.push_back(i);
        }
        return ans;
    }
};