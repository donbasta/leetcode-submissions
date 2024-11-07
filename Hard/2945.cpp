using ll = long long;

struct Segtree {
    int n;
    vector<ll> tree;
    Segtree(int n) : n(n), tree(4 * n + 5) {}
    void upd(int v, int s, int e, int idx, ll val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid) upd(v << 1, s, mid, idx, val);
        else if (idx >= mid + 1) upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
    }
    ll get_min(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return get_min(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get_min(v << 1 | 1, mid + 1, e, l, r);
        return min(get_min(v << 1, s, mid, l, mid), get_min(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    void upd(int idx, ll val) {
        upd(1, 0, n - 1, idx, val);
    }
    ll get_min(int l, int r) {
        return get_min(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pref(n);
        for (int i = 0; i < n; i++) {
            pref[i] = (i ? pref[i - 1] : 0ll) + nums[i];
        }
        Segtree sgt(n);
        vector<int> len(n);
        vector<ll> F(n);
        len[0] = 1;
        F[0] = nums[0];
        sgt.upd(0, F[0] + nums[0]);
        for (int i = 1; i < n; i++) {
            int lo = 0, hi = i - 1, piv = -1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (sgt.get_min(mid, i - 1) <= pref[i]) {
                    piv = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if (piv != -1) {
                len[i] = len[piv] + 1;
                F[i] = pref[i] - pref[piv];
            } else {
                len[i] = 1;
                F[i] = pref[i];
            }
            sgt.upd(i, F[i] + pref[i]);
        }
        return len.back();
    }
};