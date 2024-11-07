class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pw;
        for (int i = 0; i < 30; i++) {
            if ((n >> i) & 1) pw.push_back(i);
        }
        int sz = pw.size();
        vector<int> pre(sz);
        for (int i = 0; i < sz; i++) {
            pre[i] = (i ? pre[i - 1] : 0) + pw[i];
        }
        vector<int> ret;
        const int MOD = 1e9 + 7;
        auto fpow = [&](int a, int b) {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % MOD;
                a = (1ll * a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };
        for (auto e : queries) {
            int l = e[0], r = e[1];
            int sum = (pre[r] - (l ? pre[l - 1] : 0));
            ret.push_back(fpow(2, sum));
        }
        return ret;
    }
};