class Solution {
public:
    int superPow(int a, vector<int>& b) {
        const int MOD = 1337;
        const function<int(int, int)> fpow = [&](int a, int b) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % MOD;
                a = (1ll * a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };
        vector<int> pw(2005); //2^(10^i)
        pw[0] = a;
        for (int i = 1; i <= 2000; i++) {
            pw[i] = fpow(pw[i - 1], 10);
        }
        int n = b.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = (1ll * ans * fpow(pw[n - 1 - i], b[i])) % MOD;
        }
        if (ans < 0) ans += MOD;
        return ans;
    }
};