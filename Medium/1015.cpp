class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (__gcd(k, 10) > 1) return -1;
        if (k == 1) return 1;
        k *= 9;
        int nk = k;
        int phi = k;
        for (int i = 2; i * i <= nk; i++) {
            if (nk % i != 0) continue;
            while (nk % i == 0) nk /= i;
            phi = phi / i * (i - 1);
        }
        if (nk > 1) phi = phi / nk * (nk - 1);
        cout << phi << '\n';
        const function<int(int, int, int)> fpow = [&](int a, int b, int mod) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % mod;
                a = (1ll * a * a) % mod;
                b >>= 1;
            }
            return ret;
        };
        int ans = INT_MAX;
        for (int i = 1; i * i <= phi; i++) {
            if (phi % i != 0) continue;
            if (fpow(10, i, k) == 1) {
                ans = min(ans, i);
            }
            if (i * i != k) {
                if (fpow(10, phi / i, k) == 1) {
                    ans = min(ans, phi / i);
                }
            }
        }
        return ans;
    }
};