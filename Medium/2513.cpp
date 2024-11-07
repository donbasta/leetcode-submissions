class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        const int INF = 2e9;
        int l = 1, r = INF, piv = -1;
        long long tmp = 1ll * divisor1 * (divisor2 / __gcd(divisor1, divisor2));
        if (tmp > 1ll * INF) tmp = INF;
        int kpk = tmp;
        while (l <= r) {
            int mid = (1ll * l + r) >> 1;
            int x1 = (mid - 1) - (mid - 1) / divisor1;
            int x2 = (mid - 1) - (mid - 1) / divisor2;
            int x3 = (mid - 1) - (mid - 1) / kpk;
            int p = 1ll * x1 + x2 - x3;
            if (max(0, uniqueCnt1 - (x3 - x2)) + max(0, uniqueCnt2 - (x3 - x1)) <= p) {
                piv = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return piv - 1;
    }
};