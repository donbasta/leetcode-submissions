class Solution {
public:
    long long minEnd(int n, int x) {
        using ll = long long;
        ll ptr = 0, ret = x;
        ll cx = x, cn = n;
        for (int i = 0; i < 60; i++) {
            if ((cx >> i) & 1) continue;
            if (((cn - 1) >> ptr) & 1) {
                ret ^= (1ll << i);
            }
            ptr++;
        }
        return ret;
    }
};