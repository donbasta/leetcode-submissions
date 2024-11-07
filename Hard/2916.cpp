struct Segtree {
    vector<int> tree;
    static const int MOD = 1e9 + 7;
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
        else if (idx >= mid + 1) upd(v << 1 | 1, mid + 1, e, idx, val);
        tree[v] = (tree[v << 1] + tree[v << 1 | 1]) % MOD;
    }
    int get(int v, int s, int e, int l, int r) {
        if (l > r) return 0;
        if (s == l && e == r) return tree[v];
        int mid = (s + e) >> 1;
        if (r <= mid) return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
        return (1ll * get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r)) % MOD;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        const int M = 1e5;
        vector<int> le(M + 1, -1);

        Segtree sgt(n), cnt(n);
        int ans = 1;
        int ret = 1;
        le[nums[n - 1]] = n - 1;
        sgt.upd(1, 0, n - 1, n - 1, n - 1);
        cnt.upd(1, 0, n - 1, n - 1, 1);
        int unq = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (le[nums[i]] == -1) {
                ans = (ans + n - i) % MOD;
                ans = (1ll * ans + 2ll * n * unq) % MOD;
                ans = (1ll * ans - 2ll * sgt.get(1, 0, n - 1, 0, n - 1)) % MOD;
                le[nums[i]] = i;
                sgt.upd(1, 0, n - 1, le[nums[i]], i);
                cnt.upd(1, 0, n - 1, le[nums[i]], 1);

                unq++;
                ret = (ret + ans) % MOD;
            } else {
                int r = cnt.get(1, 0, n - 1, i + 1, le[nums[i]] - 1);
                ans = (ans + n - i) % MOD;
                ans = (1ll * ans + 2ll * n * r) % MOD;
                ans = (1ll * ans - 2ll * sgt.get(1, 0, n - 1, i + 1, le[nums[i]] - 1)) % MOD;
                ans = (1ll * ans - 1ll * (2 * r + 1) * (n - le[nums[i]])) % MOD;
                ret = (ret + ans) % MOD;

                sgt.upd(1, 0, n - 1, le[nums[i]], 0);
                cnt.upd(1, 0, n - 1, le[nums[i]], 0);
                le[nums[i]] = i;
                sgt.upd(1, 0, n - 1, le[nums[i]], i);
                cnt.upd(1, 0, n - 1, le[nums[i]], 1);
            }
        }
        ret %= MOD;
        if (ret < 0) ret += MOD;
        return ret;
    }
};