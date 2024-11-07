using ll = long long;

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        const int B = 62;
        auto calc = [&](ll num) -> ll {
            ll ret = 0;
            for (int i = x - 1; i <= B; i += x) {
                // 0..2^i - 1, 2^i..2*2^i - 1, 2*2^i..3*2^i - 1, ...
                ll p = (num) / (1ll << i);
                if (p % 2 == 0) {
                    ret += (p * (1ll << i)) / 2;
                } else {
                    ret += ((p - 1) * (1ll << i)) / 2 + (num % (1ll << i)) + 1;
                }
            }
            return ret;
        };

        ll lo = 1, hi = 1e16, ans = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            if (calc(mid) <= k) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};