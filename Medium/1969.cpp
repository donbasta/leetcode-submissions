class Solution {
public:
    int minNonZeroProduct(int p) {
        using ll = long long;
        ll a = (1ll << p) - 1;
        ll b = (1ll << p) - 2;
        const ll MOD = 1e9 + 7;

        auto fpow = [&](ll x, ll y) -> ll {
            ll ret = 1;
            while (y) {
                if (y & 1) ret = (ret * x) % MOD;
                x = (x * x) % MOD;
                y >>= 1;
            }
            return ret;
        };

        ll ans = a % MOD;
        ans = (ans * fpow(b % MOD, (1ll << (p - 1)) - 1)) % MOD;
        return ans;
    }
};