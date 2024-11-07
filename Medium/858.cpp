class Solution {
public:
    int mirrorReflection(int p, int q) {
        int t = __gcd(p, q);
        p /= t, q /= t;
        int ans;
        if (p & 1) {
            if (q & 1) ans = 1;
            else ans = 0;
        } else {
            assert (q & 1);
            ans = 2;
        }
        return ans;
    }
};