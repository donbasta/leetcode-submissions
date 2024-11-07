struct Segtree {
    vector<int> tree;
    Segtree(int n) : tree(4 * n + 5) {}
    void build(int v, int s, int e, vector<int>& ar) {
        if (s == e) { tree[v] = ar[s]; return; }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, ar);
        build(v << 1 | 1, mid + 1, e, ar);
        tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
    }
    void upd(int v, int s, int e, int pos, int val) {
        if (s == e) { tree[v] = val; return; }
        int mid = (s + e) >> 1;
        if (pos <= mid) upd(v << 1, s, mid, pos, val);
        else upd(v << 1 | 1, mid + 1, e, pos, val);
        tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1, mid + 1, e, l, r);
        return min(get(v << 1, s, mid, l, mid), get(v << 1 | 1, mid + 1, e, mid + 1, r));
    }
};

class Solution {
public:
    bool isTransformable(string s, string t) {
        int n = s.length();
        vector<int> ptr(10);
        vector<vector<int>> pos(10);
        const int INF = 20;
        vector<int> num(n);
        for (int i = 0; i < n; i++) {
            pos[s[i] - '0'].push_back(i);
            num[i] = s[i] - '0';
        }
        Segtree sgt(n);
        sgt.build(1, 0, n - 1, num);
        for (int i = 0; i < n; i++) {
            int cur = t[i] - '0';
            if (ptr[cur] >= pos[cur].size()) {
                return false;
            }
            int mn = sgt.get(1, 0, n - 1, 0, pos[cur][ptr[cur]]);
            if (mn < cur) return false;
            sgt.upd(1, 0, n - 1, pos[cur][ptr[cur]], INF);
            ptr[cur]++;
        }
        return true;
    }
};