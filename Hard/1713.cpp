struct Segtree {
    vector<int> tree;
    Segtree(int n) : tree(4 * n + 5) {}
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid) upd(v << 1, s, mid, idx, val);
        else upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (l > r) return 0;
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        return max(
            get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r)
        );
    }
};

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int m = target.size();
        int n = arr.size();
        Segtree sgt(n);
        unordered_map<int, vector<int>> pos;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            pos[arr[i]].push_back(i);
        }
        for (auto e : target) {
            if (!pos.count(e)) continue;
            for (auto p : pos[e]) {
                dp[p] = sgt.get(1, 0, n - 1, 0, p - 1) + 1;
            }
            for (auto p : pos[e]) {
                sgt.upd(1, 0, n - 1, p, dp[p]);
            }
        }
        int lcs = *max_element(dp.begin(), dp.end());
        return m - lcs;
    }
};