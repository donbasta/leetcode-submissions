class Solution {
public:
    bool isPerfectSquare(int num) {
        using ll = long long;
        ll L = 0, R = 1ll << 16;
        ll piv = -1;
        while (L <= R) {
            ll mid = (L + R) >> 1;
            if (mid * mid <= 1ll * num) {
                piv = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        return (piv * piv == 1ll * num);
    }
};