struct Segtree {
    int n;
    vector<int> tree;
    vector<bool> lazy;
    
    Segtree(int n) : n(n) {
        tree.resize(4 * n + 5);
        lazy.resize(4 * n + 5);
    }

    void build(int v, int s, int e, vector<int>& a) {
        if (s == e) {
            tree[v] = a[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, a);
        build(v << 1 | 1, mid + 1, e, a);
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }

    void push(int v, int s, int e) {
        if (!lazy[v]) return;
        int mid = (s + e) >> 1;
        // if (!lazy[v << 1]) tree[v << 1] = (mid - s + 1) - tree[v << 1];
        // if (!lazy[v << 1 | 1]) tree[v << 1 | 1] = (e - mid) - tree[v << 1 | 1];
        tree[v << 1] = (mid - s + 1) - tree[v << 1];
        tree[v << 1 | 1] = (e - mid) - tree[v << 1 | 1];
        lazy[v << 1] = !lazy[v << 1];
        lazy[v << 1 | 1] = !lazy[v << 1 | 1];
        // lazy[v << 1 | 1] = lazy[v << 1] = true;
        lazy[v] = false;
    }

    void upd(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            tree[v] = (e - s + 1) - tree[v];
            // lazy[v] = true;
            lazy[v] = !lazy[v];
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid) upd(v << 1, s, mid, l, r);
        else if (l >= mid + 1) upd(v << 1 | 1, mid + 1, e, l, r);
        else {
            upd(v << 1, s, mid, l, mid);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        return get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();

        Segtree s1(n);
        s1.build(1, 0, n - 1, nums1);
        
        vector<long long> ans;
        long long cur = 0;
        for (auto e :  nums2) {
            cur += e;
        }

        for (auto q : queries) {
            int type = q[0];
            if (type == 1) {
                s1.upd(1, 0, n - 1, q[1], q[2]);
                // cout << s1.get(1, 0, n - 1, 0, n - 1) << ' ';
                // cout << s1.get(1, 0, 5, 0, 2) << ' ' << s1.get(1, 0, 5, 3, 5) << ' ';
                // cout << s1.get(1, 0, 5, 3, 3) << ' ' << s1.get(1, 0, 5, 4, 4) << ' ' << s1.get(1, 0, 5, 5, 5);
                // cout << '\n';
            } else if (type == 2) {
                cur = (cur + 1ll * q[1] * s1.get(1, 0, n - 1, 0, n - 1));
            } else if (type == 3) {
                ans.push_back(cur);
            }
        }
        
        return ans;
    }
};