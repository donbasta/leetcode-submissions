class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        //n * (n - 1) * (n - 2) * ... * (n - k + 1) * (n - k) ^ (goal - k);
        const int MOD = 1e9 + 7;
        const function<int(int)> inv = [&](int a) -> int {
            int pow = MOD - 2;
            int ret = 1;
            while (pow) {
                if (pow & 1) ret = (1LL * ret * a) % MOD;
                a = (1LL * a * a) % MOD;
                pow >>= 1;
            }
            return ret;
        };
        vector<int> iv(n + 1);
        for (int i = 1; i <= n; i++) {
            iv[i] = inv(i);
        }
        const function<int(int)> f = [&](int mus) -> int {
            if (mus <= k) return 0;
            int ret = 1;
            for (int i = 0; i < k; i++) {
                ret = (1LL * ret * (mus - i)) % MOD;
            }
            for (int i = 0; i < goal - k; i++) {
                ret = (1LL * ret * (mus - k)) % MOD;
            }
            for (int i = 0; i < mus; i++) {
                ret = (1LL * ret * (n - i)) % MOD;
                ret = (1LL * ret * iv[i + 1]) % MOD;
            }
            return ret;
        };
        int ans = 0;
        for (int i = n; i >= 0; i--) {
            int mul = (((n - i) & 1) ? -1 : 1);
            ans = (1LL * ans + 1LL * mul * f(i)) % MOD;
        }
        ans = ans % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};