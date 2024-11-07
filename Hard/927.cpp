class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        vector<int> pos, cnt(n);
        for (int i = 0; i < n; i++) {
            cnt[i] = (i ? cnt[i - 1] : 0);
            if (arr[i] == 1) {
                pos.push_back(i);
            } else {
                cnt[i]++;
            }
        }
        if (pos.empty()) {
            return vector<int>{0, 2};
        }
        int fi = pos[0], ptr = 0;

        auto fpow = [&](int a, int b, int mod) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % mod;
                a = (1ll * a * a) % mod;
                b >>= 1;
            }
            return ret;
        };

        const int B = 5, M = 1000000009;
        int iB = fpow(B, M - 2, M);
        int pw[n + 1], ipw[n + 1];
        pw[0] = ipw[0] = 1; 
        for (int i = 1; i <= n; i++) {
            pw[i] = (1ll * pw[i - 1] * B) % M;
            ipw[i] = (1ll * ipw[i - 1] * iB) % M;
        }

        int pre[n];
        for (int i = 0; i < n; i++) {
            int cur = (1ll * (arr[i] + 1) * pw[i]) % M;
            pre[i] = (1ll * (i ? pre[i - 1] : 0) + cur) % M;
        }

        auto get_hash = [&](int a, int b) -> int {
            int p = (pre[b] - (a ? pre[a - 1] : 0)) % M;
            if (p < 0) p += M;
            p = (1ll * p * ipw[a]) % M;
            return p;
        };

        for (int j = fi; j < n; j++) {
            //try fi..j
            //find first position 1 after j
            while (ptr < (int)pos.size() && pos[ptr] <= j) ptr++;
            if (ptr == (int)pos.size()) {
                return vector<int>{-1, -1};
            }
            int nx = pos[ptr];
            //check if s[fi..j] == s[nx..(j + nx - fi)]
            if (j + nx - fi >= n) continue;
            bool ok = get_hash(fi, j) == get_hash(nx, j + nx - fi);
            //check also if s[fi..j] == s[(fi + n - 1 - j)..n - 1]
            if (j + nx - fi >= fi + n - 1 - j) continue;
            ok &= get_hash(fi, j) == get_hash(fi + n - 1 - j, n - 1);
            //check also if s[j + nx - fi + 1..fi + n - j - 2] all contains 0
            ok &= (cnt[fi + n - j - 2] - cnt[j + nx - fi] == (fi + n - j - 2) - (j + nx - fi));
            if (ok) {
                return vector<int>{j, j + nx - fi + 1};
            }
        }
        return vector<int>{-1, -1};
    }
};