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
    RollingHash(string s) {
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
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int ns = s.length(), na = a.length(), nb = b.length();
        vector<int> ret;
        if (na > ns || nb > ns) {
            return ret;
        }
        RollingHash HHH = RollingHash(s);
        pair<int, int> A = HHH.go_hash(a);
        pair<int, int> B = HHH.go_hash(b);
        vector<int> AA, BB;
        for (int i = 0; i <= ns - na; i++) {
            if (HHH.get_hash(i, i + na - 1) == A) {
                AA.push_back(i);
            }
        }
        for (int i = 0; i <= ns - nb; i++) {
            if (HHH.get_hash(i, i + nb - 1) == B) {
                BB.push_back(i);
            }
        }
        for (auto e : AA) {
            int idx = lower_bound(BB.begin(), BB.end(), e) - BB.begin();
            int tmp = INT_MAX;
            if (idx < (int)BB.size()) {
                tmp = min(tmp, BB[idx] - e);
            }
            if (idx > 0) {
                tmp = min(tmp, e - BB[idx - 1]);
            }
            if (tmp <= k) {
                ret.push_back(e);
            }
        }
        return ret;
    }
};