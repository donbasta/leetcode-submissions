class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        auto fpow = [&](int x, int y, int mod) -> int {
            int ret = 1;
            while (y) {
                if (y & 1) ret = (1ll * ret * x) % mod;
                x = (1ll * x * x) % mod;
                y >>= 1;
            }
            return ret;
        };

        set<vector<int>> se;
        const int P[] = {31, 37};
        const int M[] = {1000000007, 1000000009};
        for (auto w : words) {
            int cur = 0;
            vector<int> H(2), pw(2, 1);
            for (auto c : w) {
                for (int i = 0; i < 2; i++) {
                    H[i] = (1ll * H[i] + 1ll * pw[i] * (c - 'a' + 1)) % M[i];
                    pw[i] = (1ll * pw[i] * P[i]) % M[i];
                }
                se.emplace(H);
            }
        }
        int n = target.size();
        vector<int> R(n, -1), pw(2, 1);
        vector<vector<int>> X(n);
        vector<vector<int>> pre(n, vector<int>(2));
        vector<vector<int>> ipw(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                pre[i][j] = (1ll * (i ? pre[i - 1][j] : 0) + 1ll * pw[j] * (target[i] - 'a' + 1)) % M[j];
                pw[j] = (1ll * pw[j] * P[j]) % M[j];
            }
        }
        for (int i = 0; i < 2; i++) {
            int inv = fpow(P[i], M[i] - 2, M[i]);
            ipw[0][i] = 1;
            for (int j = 1; j < n; j++) {
                ipw[j][i] = (1ll * ipw[j - 1][i] * inv) % M[i];
            }
        }

        auto get_hash = [&](int l, int r) -> vector<int> {
            vector<int> H(2);
            for (int i = 0; i < 2; i++) {
                H[i] = (pre[r][i] - (l ? pre[l - 1][i] : 0)) % M[i];
                H[i] = (1ll * H[i] * ipw[l][i]) % M[i];
                if (H[i] < 0) H[i] += M[i];
            }
            return H;
        };

        for (int i = 0; i < n; i++) {
            int lo = i, hi = n - 1, piv = -1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                vector<int> T = get_hash(i, mid);
                if (se.count(T)) {
                    piv = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            R[i] = piv;
            if (piv != -1) {
                X[piv].push_back(i);
            }
        }

        const int INF = 2e9;
        vector<int> DP(n, INF);
        multiset<int> mse;
        if (R[0] >= 0) {
            DP[0] = 1;
        }
        if (R[0] >= 1) {
            mse.insert(0);
        }

        for (int i = 1; i < n; i++) {
            if (R[i] >= i) {
                mse.insert(DP[i - 1]);
            }
            if (!mse.empty()) {
                DP[i] = 1 + *mse.begin();
            }
            for (auto e : X[i]) {
                mse.erase(mse.find((e ? DP[e - 1] : 0)));
            }
        }
        if (DP.back() >= INF) return -1;
        return DP.back();
    }
};