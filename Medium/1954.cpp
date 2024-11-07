class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        using ll = long long;
        ll lo = 1, hi = 1e5;
        ll piv = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            ll count = 2ll * mid * (mid + 1);
            // ll quad = 2 * (1 + ... + mid) * mid = mid * mid * (mid + 1)
            ll quad = 4ll * mid * mid * (mid + 1);
            count += quad;
            if (count < neededApples) {
                lo = mid + 1;
            } else {
                piv = mid;
                hi = mid - 1;
            }
        }
        return piv * 8;
    }
};