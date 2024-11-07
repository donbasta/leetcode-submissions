class Solution {
public:
    int findKthNumber(int n, int k) {
        using ll = long long;
        auto F = [&](ll a, ll b) -> int {
            int ret = 0;
            while (a <= n) {
                ret += min(1ll * n + 1, b) - a;
                a *= 10, b *= 10;
            }
            return ret;
        };
        ll ans = 1, cur = 1;
        while (cur < k) {
            int x = F(ans, ans + 1);
            if (cur + x <= k) {
                cur += x, ans++;
            } else {
                cur++;
                ans *= 10;
            }
        }
        return ans;
    }
};