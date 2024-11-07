class Fancy {
public:
    vector<int> ar, lz_add, lz_mul;
    int MOD = 1e9 + 7;
    int M = 1e5;
    int sz = 0;

    Fancy() {
        ar.resize(M + 5);
        lz_mul.assign(4 * M + 5, 1);
        lz_add.resize(4 * M + 5);
    }

    void push(int v, int s, int e) {
        lz_mul[v << 1] = (1ll * lz_mul[v] * lz_mul[v << 1]) % MOD;
        lz_mul[v << 1 | 1] = (1ll * lz_mul[v] * lz_mul[v << 1 | 1]) % MOD;
        lz_add[v << 1] = (1ll * lz_mul[v] * lz_add[v << 1] + lz_add[v]) % MOD;
        lz_add[v << 1 |1] = (1ll * lz_mul[v] * lz_add[v << 1 | 1] + lz_add[v]) % MOD;
        lz_mul[v] = 1;
        lz_add[v] = 0;
    }
    
    void upd(int v, int s, int e, int l, int r, int val, int mode) {
        if (s == l && e == r) {
            if (mode == 1) {
                lz_add[v] += val;
            } else if (mode == 2) {
                lz_mul[v] = (1ll * lz_mul[v] * val) % MOD;
                lz_add[v] = (1ll * lz_add[v] * val) % MOD;
            }
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid) upd(v << 1, s, mid, l, r, val, mode);
        else if (l >= mid + 1) upd(v << 1 | 1, mid + 1, e, l, r, val, mode);
        else {
            upd(v << 1, s, mid, l, mid, val, mode);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, val, mode);
        }
    }

    int get(int v, int s, int e, int idx) {
        if (s == e) {
            return (1ll * lz_mul[v] * ar[idx] + lz_add[v]) % MOD;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (idx <= mid) return get(v << 1, s, mid, idx);
        else return get(v << 1 | 1, mid + 1, e, idx);
    }
    
    void append(int val) {
        ar[sz++] = val;
    }
    
    void addAll(int inc) {
        if (sz == 0) return;
        upd(1, 0, M - 1, 0, sz - 1, inc, 1);
    }
    
    void multAll(int m) {
        if (sz == 0) return;
        upd(1, 0, M - 1, 0, sz - 1, m, 2);
    }
    
    int getIndex(int idx) {
        if (idx >= sz) return -1;
        return get(1, 0, M - 1, idx);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */