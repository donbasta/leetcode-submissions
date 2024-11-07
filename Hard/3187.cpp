struct Segtree {
    int n;
    vector<int> tree;
    Segtree(int n) : n(n), tree(4 * n + 5) {}
    void upd(int v, int s, int e, int idx, int val) {
        if (s == e) {
            tree[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (idx <= mid) upd(v << 1, s, mid, idx, val);
        else upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    void upd(int idx, int val) {
        upd(1, 0, n - 1, idx, val);
    }
    int que(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return que(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return que(v << 1 | 1, mid + 1, e, l, r);
        return que(v << 1, s, mid, l, mid) + que(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
    int que(int l, int r) {
        return que(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ve;
        int n = nums.size();
        auto is_peak = [&](int idx) -> bool {
            return (idx > 0) && (idx < n - 1) && (nums[idx] > nums[idx - 1]) && (nums[idx] > nums[idx + 1]);
        };

        Segtree sgt(n);
        for (int i = 1; i < n - 1; i++) {
            if (is_peak(i)) sgt.upd(i, 1);
        }
        for (auto q : queries) {
            if (q[0] == 1) {
                int cur = sgt.que(q[1], q[2]);
                if (is_peak(q[1])) cur--;
                if (is_peak(q[2]) && q[2] != q[1]) cur--;
                ve.push_back(cur);
            } else {
                int idx = q[1], val = q[2];
                nums[idx] = val;
                for (int i = max(1, idx - 1); i <= min(n - 2, idx + 1); i++) {
                    if (is_peak(i)) sgt.upd(i, 1);
                    else sgt.upd(i, 0);
                }
            }
        }
        return ve;
    }
};