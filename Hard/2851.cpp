class Solution {
public:
    int numberOfWays(string s, string t, long long k) {
        const int MOD = 1e9 + 7;
        const int B = 31;
        const function<int(int, long long)> fpow = [&](int a, long long b) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % MOD;
                a = (1ll * a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };
        int n = s.length();
        vector<vector<int>> rollhash(2, vector<int>(n));
        vector<vector<pair<int, int>>> hashcut(2, vector<pair<int, int>>(n - 1));
        int pw = 1;
        int invb = fpow(B, MOD - 2);
        vector<int> invB(n);
        invB[0] = 1;
        for (int i = 1; i < n; i++) {
            invB[i] = (1ll * invB[i - 1] * invb) % MOD;
        }
        for (int i = 0; i < n; i++) {
            rollhash[0][i] = (1ll * pw * (s[i] - 'a' + 1) + (i ? rollhash[0][i - 1] : 0)) % MOD;
            rollhash[1][i] = (1ll * pw * (t[i] - 'a' + 1) + (i ? rollhash[1][i - 1] : 0)) % MOD;
            pw = (1ll * pw * B) % MOD;
        }
        const function<int(int, int, int)> hash = [&](int idx, int a, int b) -> int {
            int lmao = (rollhash[idx][b] - (a ? rollhash[idx][a - 1] : 0)) % MOD;
            lmao = (1ll * lmao * invB[a]) % MOD;
            if (lmao < 0) lmao += MOD;
            return lmao;
        };
        for (int idx = 0; idx < 2; idx++) {
            for (int i = 0; i <= n - 2; i++) {
                int le = hash(idx, 0, i);
                int ri = hash(idx, i + 1, n - 1);
                hashcut[idx][i] = make_pair(le, ri);
            }
        }
        int res = 0, resnol = 0;
        for (int i = 0; i <= n - 2; i++) {
            if (hashcut[0][i].first == hashcut[1][n - 2 - i].second && hashcut[0][i].second == hashcut[1][n - 2 - i].first) {
                res++;
            }
        }
        if (hash(0, 0, n - 1) == hash(1, 0, n - 1)) {
            resnol++;
        }
        if (res + resnol == 0) return 0;
        //a_1 + a_2 + ... + a_k = c (mod n) for c in cyc, and 1 <= a_i <= n-1
        int invn = fpow(n, MOD - 2);
        int ik = ((k & 1) ? (-1) : 1);
        int nk = fpow(n - 1, k);
        int rek = (nk - ik) % MOD;
        rek = (1ll * rek * invn) % MOD;
        rek = (1ll * rek * res) % MOD;
        if (resnol) {
            int reknol = (1ll * nk + 1ll * (n - 1) * ik) % MOD;
            reknol = (1ll * reknol * invn) % MOD;
            rek = (rek + reknol) % MOD;
        }
        return rek;
    }
};