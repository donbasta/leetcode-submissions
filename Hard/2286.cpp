class BookMyShow {
private:
    int _n, _m;
    vector<long long> mx, sm;
    vector<long long> lazyMx;
    vector<int> firstEmpty;

    // build the segtree
    void build(int v, int s, int e) {
        if (s == e) {
            mx[v] = sm[v] = _m;
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
        sm[v] = sm[v << 1] + sm[v << 1 | 1];
    }

    void push(int v, int s, int e) {
        if (lazyMx[v] != -1) {
            long long lm = lazyMx[v];
            lazyMx[v << 1] = lazyMx[v << 1 | 1] = lm;
            mx[v << 1] = mx[v << 1 | 1] = lm;

            int mid = (s + e) >> 1;
            sm[v << 1] = lm * (mid - s + 1);
            sm[v << 1 | 1] = lm * (e - mid);

            lazyMx[v] = -1;
        }
    }

    // update those in range [l, r] to val
    void upd(int v, int s, int e, int l, int r, int val) { 
        if (s == l && e == r) {
            mx[v] = lazyMx[v] = val;
            sm[v] = 1ll * val * (e - s + 1);
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid) {
            upd(v << 1, s, mid, l, r, val);
        } else if (l >= mid + 1) {
            upd(v << 1 | 1, mid + 1, e, l, r, val);
        } else {
            upd(v << 1, s, mid, l, mid, val);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r, val);
        }
        mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
        sm[v] = sm[v << 1] + sm[v << 1 | 1];
    }

    long long queMax(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return mx[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid) {
            return queMax(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            return queMax(v << 1 | 1, mid + 1, e, l, r);
        } 
        return max(queMax(v << 1, s, mid, l, mid), queMax(v << 1 | 1, mid + 1, e, mid + 1, r));
    }

    long long queSum(int v, int s, int e, int l, int r) {
        if (s == l && e == r) return sm[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid) {
            return queSum(v << 1, s, mid, l, r);
        } else if (l >= mid + 1) {
            return queSum(v << 1 | 1, mid + 1, e, l, r);
        } 
        return queSum(v << 1, s, mid, l, mid) + queSum(v << 1 | 1, mid + 1, e, mid + 1, r);
    }

public:
    BookMyShow(int n, int m) {
        _n = n;
        _m = m;
        mx.resize(4 * n + 5), sm.resize(4 * n + 5);
        lazyMx.assign(4 * n + 5, -1);
        build(1, 0, n - 1);
        firstEmpty.assign(n, 0);
    }

    vector<int> gather(int k, int maxRow) {
        int l = 0, r = maxRow;
        int can = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (queMax(1, 0, _n - 1, 0, mid) >= k) {
                can = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        vector<int> ret;
        if (can == -1) return ret;

        ret = {can, firstEmpty[can]};
        firstEmpty[can] += k;
        int curCan = queMax(1, 0, _n - 1, can, can);
        upd(1, 0, _n - 1, can, can, curCan - k);
        return ret;
    }

    bool scatter(int k, int maxRow) {
        int l = 0, r = maxRow;
        int can = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (queSum(1, 0, _n - 1, 0, mid) >= k) {
                can = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (can == -1) return false;
    
        long long prv = (can ? queSum(1, 0, _n - 1, 0, can - 1) : 0);
        long long needOnCan = k - prv;
        int curCan = queMax(1, 0, _n - 1, can, can);
        if (can) upd(1, 0, _n - 1, 0, can - 1, 0);
        upd(1, 0, _n - 1, can, can, curCan - needOnCan);
        firstEmpty[can] += needOnCan;
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */