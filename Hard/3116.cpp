class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        using ll = long long;
        
        int n = coins.size();

        const ll INF = 2e18;
        auto lcm = [&](ll x, ll y) -> ll {
            ll fpb = __gcd(x, y);
            if ((x / fpb) > (INF / y)) {
                return INF;
            }
            return x * (y / fpb);
        };
        
        ll lo = 1, hi = INF;
        ll ans = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll tmp = 0;
            for (int i = 1; i < (1 << n); i++) {
                ll kpk = 1;
                for (int j = 0; j < n; j++) {
                    if ((i >> j) & 1) kpk = lcm(kpk, coins[j]);
                }
                if (__builtin_popcount(i) & 1) {
                    tmp += ((mid - 1) / kpk);
                } else {
                    tmp -= ((mid - 1) / kpk);
                }
            }
            // cout << mid << ' ' << tmp << '\n';
            if (tmp >= k) {
                hi = mid - 1;
            } else if (tmp <= k - 1) {
                ans = mid;
                lo = mid + 1;
            }
        }

        return ans;
    }
};