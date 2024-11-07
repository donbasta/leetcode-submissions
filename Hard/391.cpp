struct Segtree {
    int tree[800069], lazy[800069];
    Segtree() {
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
    }
    void pull(int v) {
        if (lazy[v] != 0) {
            lazy[v << 1] += lazy[v];
            lazy[v << 1 | 1] += lazy[v];
            tree[v << 1] += lazy[v];
            tree[v << 1 | 1] += lazy[v];
            lazy[v] = 0;
        }
    }
    void upd(int v, int s, int e, int l, int r, int val) {
        if (s == l && e == r) {
            tree[v] += val;
            lazy[v] += val;
            return;
        }
        pull(v);
        int mid = (s + e) >> 1;
        if (r <= mid) upd(v << 1, s, mid, l, r, val);
        else if (l >= mid + 1) upd(v << 1 | 1, mid + 1, e, l, r, val);
        else {
            upd(v << 1, s, mid, l, mid, val);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, val);
        }
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        pull(v);
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        else {
            return max(
                get(v << 1, s, mid, l, mid),
                get(v << 1 | 1, mid + 1, e, mid + 1, r)
            );
        }
    }
};

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int MX = 1e5;
        vector<vector<vector<int>>> open(2 * MX + 1), close(2 * MX + 1);
        long long tot_area = 0, region_area;
        int mn_x = 2e9, mx_x = -2e9, mn_y = 2e9, mx_y = -2e9;
        for (int i = 0; i < rectangles.size(); i++) {
            for (int j = 0; j < 4; j++) {
                rectangles[i][j] += MX;
            }
            int x = rectangles[i][0], y = rectangles[i][1], a = rectangles[i][2], b = rectangles[i][3];
            tot_area += 1ll * (b - y) * (a - x);
            open[x].push_back({y, b});
            close[a].push_back({y, b});
            mn_x = min(mn_x, x), mn_y = min(mn_y, y), mx_x = max(mx_x, a), mx_y = max(mx_y, b);
        }
        region_area = 1ll * (mx_y - mn_y) * (mx_x - mn_x);
        Segtree sgt;
        for (int i = 0; i <= 2 * MX; i++) {
            for (auto e : close[i]) {
                sgt.upd(1, 0, 2 * MX, e[0], e[1] - 1, -1);
            }
            for (auto e : open[i]) {
                sgt.upd(1, 0, 2 * MX, e[0], e[1] - 1, 1);
            }
            if (sgt.get(1, 0, 2 * MX, 0, 2 * MX) > 1) {
                return false;
            }
        }
        return tot_area == region_area;
    }
};