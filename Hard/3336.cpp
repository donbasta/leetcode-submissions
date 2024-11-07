const int MOD = 1e9 + 7;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        vector<int> cnt(201), mul(201);
        for (auto e : nums) cnt[e]++;
        for (int i = 1; i <= 200; i++) {
            for (int j = i; j <= 200; j += i) {
                mul[i] += cnt[j];
            }
        }

        auto fpow = [&](int a, int b) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) { ret = (1ll * ret * a) % MOD; }
                a = (1ll * a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };

        int F[201][201];
        memset(F, 0, sizeof(F));
        for (int i = 200; i >= 1; i--) {
            for (int j = 200; j >= 1; j--) {
                int kpk = i * (j / __gcd(i, j));
                int isect = (kpk > 200 ? 0 : mul[kpk]);
                int A = mul[i] - isect, B = mul[j] - isect, C = isect;
                int tmp = (1ll * fpow(2, A) * fpow(2, B)) % MOD;
                tmp = (1ll * tmp * fpow(3, C)) % MOD;
                tmp = (tmp - fpow(2, B + C)) % MOD;
                tmp = (tmp - fpow(2, A + C)) % MOD;
                tmp = (tmp + 1) % MOD;
                for (int mi = i; mi <= 200; mi += i) {
                    for (int mj = j; mj <= 200; mj += j) {
                        if (mi == i && mj == j) continue;
                        tmp = (tmp - F[mi][mj]) % MOD;
                    }
                }
                if (tmp < 0) tmp += MOD;
                F[i][j] = tmp;
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= 200; i++) {
            ans = (ans + F[i][i]) % MOD;
        }
        return ans;
    }
};