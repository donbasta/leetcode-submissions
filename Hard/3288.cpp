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
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        return max(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
    void upd(int idx, int val) {
        upd(1, 0, n - 1, idx, val);
    }
    int get(int l, int r) {
        if (l > r) return 0;
        return get(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    int maxPathLength(vector<vector<int>>& co, int k) {
        int n = co.size();
        int xa = co[k][0], ya = co[k][1];
        sort(co.begin(), co.end(), [&](vector<int>& a, vector<int>& b) -> bool {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int id = -1;
        for (int i = 0; i < n; i++) {
            if (co[i][0] == xa && co[i][1] == ya) {
                id = i;
                break;
            }
        }
        assert (id != -1);
        vector<int> abs;
        for (int i = 0; i < n; i++) abs.push_back(co[i][1]);
        sort(abs.begin(), abs.end());
        abs.resize(unique(abs.begin(), abs.end()) - abs.begin());
        int sz = abs.size();
        Segtree s1(sz), s2(sz);

        int p1 = id;
        while (p1 < n && co[p1][0] == xa) p1++;
        while (p1 < n) {
            int p2 = p1, cur_val = co[p1][0];
            while (p2 < n && co[p2][0] == cur_val) {
                p2++;
            }
            vector<pair<int, int>> ve;
            for (int i = p1; i < p2; i++) {
                if (co[i][1] <= ya) continue;
                int u = lower_bound(abs.begin(), abs.end(), co[i][1]) - abs.begin();
                int mx = s1.get(0, u - 1) + 1;
                ve.emplace_back(u, mx);
            }
            for (auto e : ve) {
                s1.upd(e.first, e.second);
            }
            p1 = p2;
        }
        p1 = id;
        while (p1 >= 0 && co[p1][0] == xa) p1--;
        while (p1 >= 0) {
            int p2 = p1, cur_val = co[p1][0];
            while (p2 >= 0 && co[p2][0] == cur_val) {
                p2--;
            }
            vector<pair<int, int>> ve;
            for (int i = p1; i > p2; i--) {
                if (co[i][1] >= ya) continue;
                int u = lower_bound(abs.begin(), abs.end(), co[i][1] + 1) - abs.begin();
                int mx = s2.get(u, sz - 1) + 1;
                ve.emplace_back(u - 1, mx);
            }
            for (auto e : ve) {
                s2.upd(e.first, e.second);
            }
            p1 = p2;
        }
        // cout << s1.get(0, sz - 1) << '\n';
        // cout << s2.get(0, sz - 1) << '\n';
        return 1 + s1.get(0, sz - 1) + s2.get(0, sz - 1);
    }
};