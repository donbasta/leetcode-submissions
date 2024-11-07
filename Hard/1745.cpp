class Solution {
public:
    const long long MOD = 1e9 + 7;
    int N;
    int BASE = 31;

    vector<long long> pre, fpre, inv;

    long long fpow(long long a, long long b, long long mod) {
        long long ret = 1;
        while (b) {
            if (b & 1) ret = (ret * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ret;
    }

    void makeInv() {
        inv.resize(N + 5);
        long long inv_base = fpow(BASE, MOD - 2, MOD);
        inv[0] = 1;
        for (int i = 1; i <= N; i++) {
            inv[i] = (inv[i - 1] * inv_base) % MOD;
        }
    }

    void makeHash(string s) {
        long long pw = BASE;
        int n = s.length();
        pre[0] = (s[0] - 'a' + 1);
        for (int i = 1; i < n; i++) {
            pre[i] = (pre[i - 1] + pw * (s[i] - 'a' + 1)) % MOD;
            pw = (pw * BASE) % MOD;
        }
        pw = BASE;
        fpre[n - 1] = (s[n - 1] - 'a' + 1);
        for (int i = n - 2; i >= 0; i--) {
            fpre[i] = (fpre[i + 1] + pw * (s[i] - 'a' + 1)) % MOD;
            pw = (pw * BASE) % MOD;
        }
    }

    long long getHash(int l, int r) {
        long long ret = (pre[r] - (l ? pre[l - 1] : 0)) % MOD;
        ret = (ret * inv[l]) % MOD;
        ret = (ret + MOD) % MOD;
        return ret;
    }

    long long getHashReverse(int l, int r) {
        long long ret = (fpre[l] - ((r < N - 1) ? fpre[r + 1] : 0)) % MOD;
        ret = (ret * inv[N - 1 - r]) % MOD;
        ret = (ret + MOD) % MOD;
        return ret;
    }

    bool isPalindrome(int i, int j) {
        int len = (j - i + 1);
        if (len <= 1) return true;
        if (len & 1) {
            return getHash(i, (i + j) / 2 - 1) == getHashReverse((i + j) / 2 + 1, j);
        }
        return getHash(i, (i + j) / 2) == getHashReverse((i + j) / 2 + 1, j);

    }

    bool checkPartitioning(string s) {
        int n = s.length();
        N = n;
        pre.resize(N), fpre.resize(N);

        vector<vector<bool>> dp(n, vector<bool>(3));

        makeHash(s);
        makeInv();

        for (int i = 0; i < n; i++) {
            dp[i][0] = isPalindrome(0, i);
        }
        for (int i = 0; i < n; i++) {
            bool tmp = false;
            for (int j = 0; j < i; j++) {
                if (dp[j][0] && isPalindrome(j + 1, i)) tmp = true;
            }
            dp[i][1] = tmp;
        }
        for (int i = 0; i < n; i++) {
            bool tmp = false;
            for (int j = 0; j < i; j++) {
                if (dp[j][1] && isPalindrome(j + 1, i)) tmp = true;
            }
            dp[i][2] = tmp;
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         cout << i << ' ' << j << ' ' << s.substr(i, j - i + 1) << ' ' << isPalindrome(i, j) << '\n';
        //     }
        // }

        // for (int i = 0; i < n; i++) {
        //     cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
        // }

        return dp[n - 1][2];
    }
};