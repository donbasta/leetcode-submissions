struct Segtree {
    vector<int> tree;
    Segtree(int n) {
        tree.resize(4 * n + 5);
    }
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
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        Segtree seg(n);
        seg.upd(1, 0, n - 1, 0, nums[0]);
        for (int i = 1; i < n; i++) {
            int now = nums[i] + seg.get(1, 0, n - 1, max(0, i - k), i - 1); 
            seg.upd(1, 0, n - 1, i, now);
        }
        return seg.get(1, 0, n - 1, n - 1, n - 1);
    }
};