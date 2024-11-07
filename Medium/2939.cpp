class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long la = (a >> n), lb = (b >> n);
        long long xa = a, xb = b;
        long long mx_mask = (1ll << 50) - 1;
        const long long MOD = 1e9 + 7;
        int last = -1;
        for (int i = 0; i < n; i++) {
            int ca = ((a >> i) & 1), cb = ((b >> i) & 1);
            if (ca == cb) {
                xa = (xa | (1ll << i)), xb = (xb | (1ll << i));
            } else {
                if (la == lb) {
                    xa = (xa & (mx_mask ^ (1ll << i))), xb = (xb | (1ll << i));
                    last = i;
                } else if (la > lb) {
                    xa = (xa & (mx_mask ^ (1ll << i))), xb = (xb | (1ll << i));
                } else {
                    xb = (xb & (mx_mask ^ (1ll << i))), xa = (xa | (1ll << i));
                }
            }
        }
        if (last != -1) {
            xb = (xb & (mx_mask ^ (1ll << last))), xa = (xa | (1ll << last));
        }
        xa %= MOD;
        xb %= MOD;
        int ret = (xa * xb) % MOD;
        return ret;
    }
};