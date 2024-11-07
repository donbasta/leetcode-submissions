using ll = long long;

int fpow(int a, int b, int mod) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1ll * ret * a) % mod;
        a = (1ll * a * a) % mod;
        b >>= 1;
    }
    return ret;
}

struct RollingHash {
    const vector<int> B = {31, 37};
    const vector<int> M = {1000000007, 1000000009};
    vector<int> H[2], pw[2], ipw[2];
    int iB[2];
    RollingHash() {}
    RollingHash(int n) {
        pw[0].resize(n + 1), pw[1].resize(n + 1);
        ipw[0].resize(n + 1), ipw[1].resize(n + 1);
        pw[0][0] = pw[1][0] = ipw[0][0] = ipw[1][0] = 1;
        for (int i = 0; i < 2; i++) {
            iB[i] = fpow(B[i], M[i] - 2, M[i]);
            for (int j = 1; j <= n; j++) {
                pw[i][j] = (1ll * pw[i][j - 1] * B[i]) % M[i];
                ipw[i][j] = (1ll * ipw[i][j - 1] * iB[i]) % M[i];
            }
        }
    }
    RollingHash(const string& s) {
        int n = s.length();
        H[0].resize(n), H[1].resize(n);
        pw[0].resize(n + 1), pw[1].resize(n + 1);
        ipw[0].resize(n + 1), ipw[1].resize(n + 1);
        pw[0][0] = pw[1][0] = ipw[0][0] = ipw[1][0] = 1;
        for (int i = 0; i < 2; i++) {
            iB[i] = fpow(B[i], M[i] - 2, M[i]);
            for (int j = 1; j <= n; j++) {
                pw[i][j] = (1ll * pw[i][j - 1] * B[i]) % M[i];
                ipw[i][j] = (1ll * ipw[i][j - 1] * iB[i]) % M[i];
            }
            H[i][0] = (s[0] - 'a' + 1);
            for (int j = 1; j < n; j++) {
                H[i][j] = (1ll * H[i][j - 1] + 1ll * (s[j] - 'a' + 1) * pw[i][j]) % M[i];
            }
        }
    }
    pair<int, int> get_hash(int a, int b) {
        vector<int> X(2);
        for (int i = 0; i < 2; i++) {
            int hsh = (H[i][b] - (a ? H[i][a - 1] : 0)) % M[i];
            if (hsh < 0) hsh += M[i];
            hsh = (1ll * hsh * ipw[i][a]) % M[i];
            X[i] = hsh;
        }
        return make_pair(X[0], X[1]);
    }
    pair<int, int> go_hash(const string& S) {
        vector<int> X(2);
        int n = S.length();
        for (int i = 0; i < 2; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp = (1ll * tmp + 1ll * (S[j] - 'a' + 1) * pw[i][j]) % M[i];
            }
            X[i] = tmp;
        }
        return make_pair(X[0], X[1]);
    }
};

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        // (lb / la) * la

        RollingHash H(a), I(b);
        int la = a.length(), lb = b.length();

        if (lb <= la) {
            for (int i = 0; i <= la - lb; i++) {
                if (H.get_hash(i, i + lb - 1) == I.get_hash(0, lb - 1)) return 1;
            }
        }

        vector<pair<int, int>> pr(la), su(la);
        for (int i = 0; i < la; i++) {
            pr[i] = H.get_hash(0, i);
            su[i] = H.get_hash(i, la - 1);
        }

        set<pair<int, int>> sp, ss;
        for (auto p : pr) sp.insert(p);
        for (auto s : su) ss.insert(s);

        string tmp;
        const int INF = 2e9;
        int ans = INF;
        for (int i = 0; i <= min(la, lb); i++) {
            if (i > 0 && !ss.count(I.get_hash(0, i - 1))) continue;
            int p = i;
            bool ok = true;
            int part = (i > 0);
            while (p + la - 1 < lb) {
                if (I.get_hash(p, p + la - 1) != H.get_hash(0, la - 1)) {
                    ok = false;
                    break;
                }   
                part++;
                p += la;
            }
            if (p < lb && !sp.count(I.get_hash(p, lb - 1))) ok = false;
            if (!ok) continue;
            if (p < lb) part++;
            // cout << i << ' ' << part << '\n';
            ans = min(ans, part);
        }

        if (ans == INF) return -1;
        return ans;
    }
};